// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2023 Mathias Alejandro Jave Diaz

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_vcc;
  pin_t pin_a0;
  pin_t pin_gnd;
  uint32_t water_attr;
  uint32_t threshold_attr;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_vcc = pin_init("A0", ANALOG);
  chip->water_attr = attr_init("water",0);
  chip->threshold_attr = attr_init("threshold",50);
  chip->pin_vcc = pin_init("VCC", INPUT_PULLDOWN);
  chip->pin_gnd = pin_init("GND", INPUT_PULLUP);

  const timer_config_t timer_config = {
     .callback = chip_timer_event,
     .user_data = chip
  };

  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 1000, true);
}

void chip_timer_event(void *user_data){
  chip_state_t *chip = (chip_state_t*)user_data;
  float voltage = (attr_read_float(chip->water_attr))*3.3/100;
  if (pin_read(chip->pin_vcc) && !pin_read(chip->pin_gnd)){
    pin_dac_write(chip->pin_a0, voltage);
    if(voltage < 1351)
      pin_write(chip->pin_a0, HIGH);
    else
      pin_write(chip->pin_a0, LOW);
   }
  }
