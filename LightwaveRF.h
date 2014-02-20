// LightwaveRF.h
//
// LightwaveRF 434MHz interface for Arduino
// 
// Author: Lawrie Griffiths (lawrie.griffiths@ntlworld.com)
// Copyright (C) 2012 Lawrie Griffiths

#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define NULL 0
#define CHANGE 1

#ifdef __cplusplus
extern "C"{
#endif
typedef uint8_t boolean;
typedef uint8_t byte;

#if !defined(NULL)
#endif
#ifdef __cplusplus
}
#endif

#define LW_OFF 0
#define LW_ON 1
#define LW_MOOD 2

extern void lw_tx_setup(int tx_pin);

extern void lw_rx_setup(int rx_pin);

extern boolean lw_setup(int tx_pin, int rx_pin);

extern void lw_setup();

extern void lw_rx_wait();

extern boolean lw_have_message();

extern boolean lw_get_message(byte* buf, byte* len);

extern void lw_send(byte* msg);

extern void lw_cmd(byte level, byte channel, byte cmd, byte* id);

extern void lw_get_error_stats(long *inv);
