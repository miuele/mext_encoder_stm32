#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
 
#include "encoder_mbed.h"
#include <mstd_atomic>
 
namespace mext {

class Qei {
public:
	explicit Qei(PinName pin1, PinName pin2)
		: revert_(false)
	{
		if (mhal::encoder_pin_polarity(pin1, pin2) == mhal::encoder_pin_polarity_rev) {
			mhal::encoder_init(&enc_, pin2, pin1);
			revert_ = true;
		} else { // polarity_syn or polarity_none
			mhal::encoder_init(&enc_, pin1, pin2);
		}
		resol_ = mhal::encoder_counter_resolution(&enc_);
		write_zero();
	}

	int counter() const {

		std::int32_t cnt;

		if (resol_ == mhal::encoder_counter_resolution_32bit) {
			cnt = static_cast<std::int32_t>(mhal::encoder_read(&enc_));
		} else {
			cnt = static_cast<std::int16_t>(mhal::encoder_read(&enc_));
		}

		if (revert_) {
			cnt = -cnt;
		}

		return static_cast<int>(cnt);
	}

	void write_zero() {
		mhal::encoder_write(&enc_, 0);
	}
	
	~Qei() {
		mhal::encoder_free(&enc_);
	}

private:
	DeepSleepLock lock;
	mhal::encoder_t enc_;
	mhal::encoder_counter_resolution_t resol_;
	bool revert_;
};
 
template <class T = int>
class Encoder {
public:
	static_assert(std::is_integral<T>::value, "T must be integral");

	explicit Encoder(PinName pin1, PinName pin2, int offset = 0)
		: accumulated_ticks_(offset), qei_(pin1, pin2)
	{
	}

	int counter() const {
		return qei_.counter();
	}
 
	T ticks() const {
		CriticalSectionLock lock;
		return qei_.counter() + accumulated_ticks_;
	}
 
	void accumulate() {
		CriticalSectionLock lock;
 
		accumulated_ticks_ += qei_.counter();
		qei_.write_zero();
	}
 
	void reset(int offset = 0) {
		CriticalSectionLock lock;

		accumulated_ticks_ = offset;
		qei_.write_zero();
	}
 
private:
	T accumulated_ticks_;
	Qei qei_;
};
 
}
 
#endif
