/*
 * $Date$
 * $Author$
 * $Revision$
 */

#ifndef RENA_H
#define RENA_H

#include <types.h>

#define RENA_FM            (1 <<  0)
#define RENA_ENS           (1 <<  1)
#define RENA_ENF           (1 <<  2)
#define RENA_DS            (3)
#define RENA_POLPOS        (1 << 11) 
#define RENA_POLNEG        (0 << 11)
#define RENA_DF            (12)
#define RENA_SIEZA_450     (0 << 20)
#define RENA_SIEZA_1000    (1 << 20)
#define RENA_SEL           (21)
#define RENA_RSEL_VREFLO   (0 << 25)
#define RENA_RSEL_VREFHI   (1 << 25)
#define RENA_RANGE_15fF    (0 << 26)
#define RENA_RANGE_60fF    (1 << 26)
#define RENA_PZSEL_EN      (1 << 27)
#define RENA_PDWN          (1 << 28)
#define RENA_GAIN          (29)
#define RENA_FETSEL_SIMPLE (1 << 31)

#define RENA_FPDWN         (1 <<  0)
#define RENA_ECAL          (1 <<  1)
#define RENA_FB_TC         (1 <<  2)

typedef struct {
    volatile uint32_t control_status;          // 0x00
    volatile uint32_t rena_status;             // 0x04
    volatile uint32_t config_low;              // 0x08
    volatile uint32_t config_high;             // 0x0C
    volatile uint32_t acquire_time;            // 0x10
    volatile uint32_t slow_channel_mask_low;        // 0x14
    volatile uint32_t slow_channel_mask_high;       // 0x18
    volatile uint32_t token_count;             // 0x1c
    volatile uint32_t fast_trigger_chain_low;  // 0x20
    volatile uint32_t fast_trigger_chain_high; // 0x24
    volatile uint32_t slow_trigger_chain_low;  // 0x28
    volatile uint32_t slow_trigger_chain_high; // 0x2C
    volatile uint32_t slow_channel_force_mask_low;  // 0x30
    volatile uint32_t slow_channel_force_mask_high; // 0x34
    volatile uint32_t reserved_0;              // 0x38
    volatile uint32_t test_generator;          // 0x3C
    volatile uint32_t fast_channel_mask_low;        // 0x40
    volatile uint32_t fast_channel_mask_high;       // 0x44
    volatile uint32_t fast_channel_force_mask_low;  // 0x48
    volatile uint32_t fast_channel_force_mask_high; // 0x4c
    volatile uint32_t trap_count;                   // 0x50
} rena_t;


// define some readable mode names
#define RENA_MODE_IDLE      (0)
#define RENA_MODE_ACQUIRE   (2)
#define RENA_MODE_FOLLOW    (9)


// definitions for test generator
#define RENA_TEST_POL_PIN   (31)
#define RENA_TEST_POL_POS   (0)
#define RENA_TEST_POL_NEG   (1)


extern rena_t *rena; // 0x80000d00;


// low level functions
uint32_t rena_channel_config(uint8_t channel, uint8_t high_config, uint32_t low_config);
uint32_t rena_channel_config_verbose(uint8_t channel, uint8_t high_config, uint32_t low_config);


// monitor functions
uint32_t rena_controller_status( void);
uint32_t rena_status( void);
uint32_t rena_channel_config_function( void);
uint32_t rena_acquire_function( void);
uint32_t rena_stop_function( void);
uint32_t rena_chains_function( void);
uint32_t rena_read_token( void);
uint32_t rena_demo_config_function( void);
uint32_t rena_powerdown_config_function( void);
uint32_t rena_follow_mode( uint8_t channel);
uint32_t rena_set_ecal( uint8_t channel);
uint32_t rena_testgen( uint8_t polarity, uint16_t cycles);

// simulation functions
void rena_simulate_follower_mode( void);

#endif // RENA_H