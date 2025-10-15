// Purpose: bare-metal ARM demo to exercise SmartTimer MMIO (W1P/W1C)
#include <stdint.h>

#define SMART_BASE  0x70000000u
#define OFF_CTRL    0x00u
#define OFF_PERIOD  0x04u
#define OFF_DUTY    0x08u
#define OFF_STATUS  0x0Cu

static inline void mmio_w(uint32_t off, uint32_t v) {
    *(volatile uint32_t *)(SMART_BASE + off) = v;
}
static inline uint32_t mmio_r(uint32_t off) {
    return *(volatile uint32_t *)(SMART_BASE + off);
}

// crude delay loop (~1 second at ~100MHz CPU clock)
static inline void delay_1s(void)
{
    volatile uint32_t count = 1000000; // adjust as per CPU clock
    while (count--){}
        //__asm__ volatile("nop");
}

int main(void) {
    // EN=1, then program PERIOD/DUTY
    
    // while (1)
    // {
    mmio_w(OFF_CTRL, 0x1);
    mmio_w(OFF_PERIOD, 100);
    mmio_w(OFF_DUTY, 25);

    // W1P: pulse reset bit (bit1); should not latch on readback
    mmio_w(OFF_CTRL, 0x2);

    // W1C: clear WRAP (bit0) if set
    if (mmio_r(OFF_STATUS) & 0x1)
        mmio_w(OFF_STATUS, 0x1);
    delay_1s();// idel for each second
    // Idle forever; observe via Renode peripheral access logs
    while(1){}
}

