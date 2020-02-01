#ifndef CUSTOM_STATE_DATA_H_INCLUDED
#define CUSTOM_STATE_DATA_H_INCLUDED

#include <stdint.h>

typedef struct custom_state_data_desc_tag
{
  uint16_t delay_first_time_on;
  uint16_t delay_on_dark;
  uint16_t delay_on_wet;
  uint16_t delay_on_turn_off;

  uint16_t delay_blink_failure_led;

  uint8_t is_on_dark;
  uint8_t is_on_wet;
  uint8_t is_failure;
} custom_state_data_desc_t;

extern custom_state_data_desc_t g_state_data;

#endif /* CUSTOM_STATE_DATA_H_INCLUDED */
