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

void lw_tx_setup(int tx_pin);

void lw_rx_setup(int rx_pin);

void lw_setup();

boolean lw_setup_pins(int tx_pin, int rx_pin);

void lw_rx_wait();

boolean lw_have_message();

boolean lw_get_message(byte* buf, byte* len);

void lw_send(byte* msg);

void lw_cmd(byte level, byte channel, byte cmd, byte* id);

void lw_get_error_stats(long *inv);

