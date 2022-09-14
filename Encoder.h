#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
 
#include "encoder_mbed.h"
#include <mstd_atomic>
 
namespace mext {
 
template <class T = int>
class Encoder {
public:
    static_assert(std::is_integral<T>::value, "T must be integral");

    explicit Encoder(PinName pin1, PinName pin2)
        : accumulated_ticks_(), revert_(false)
    {
        if (mhal::encoder_pin_polarity(pin1, pin2) == mhal::encoder_pin_polarity_rev) {
            mhal::encoder_init(&enc_, pin2, pin1);
            revert_ = true;
        } else { // polarity_syn or polarity_none
            mhal::encoder_init(&enc_, pin1, pin2);
        }
        resol_ = mhal::encoder_counter_resolution(&enc_);
        reset_counter();
    }

    int counter() const {
        return static_cast<int>(read_from_counter());
    }
 
    T accumulated_ticks() const {
        return accumulated_ticks_.load(mstd::memory_order_relaxed);
    }

    T ticks() const {
        CriticalSectionLock lock;
        return counter() + accumulated_ticks();
    }
 
    void accumulate() {
        CriticalSectionLock lock;
 
        accumulated_ticks_.fetch_add(read_from_counter(), mstd::memory_order_relaxed);
        reset_counter();
    }
 
    void reset() {
        CriticalSectionLock lock;

        accumulated_ticks_.store(0, mstd::memory_order_relaxed);
        reset_counter();
    }
    
    ~Encoder() {
        mhal::encoder_free(&enc_);
    }
 
private:
 
    std::int32_t read_from_counter() const {

        std::int32_t cnt;

        if (resol_ == mhal::encoder_counter_resolution_32bit) {
            cnt = static_cast<std::int32_t>(mhal::encoder_read(&enc_));
        } else {
            cnt = static_cast<std::int16_t>(mhal::encoder_read(&enc_));
        }

        if (revert_) {
            cnt = -cnt;
        }

        return cnt;
    }
 
    void reset_counter() {
        mhal::encoder_write(&enc_, 0);
    }

    DeepSleepLock lock;

    mhal::encoder_t enc_;
 
    mstd::atomic<T> accumulated_ticks_; // ISR atomicity required here because the read has to be atomic
    mhal::encoder_counter_resolution_t resol_;
    bool revert_;
};
 
}
 
#endif
