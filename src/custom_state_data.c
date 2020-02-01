#include <custom_state_data.h>

custom_state_data_desc_t g_state_data =
{
  .delay_first_time_on = 300U,
  .delay_on_dark = 100U,
  .delay_on_wet = 100U,

  .delay_blink_failure_led = 1U,

  .is_on_dark = 0,
  .is_on_wet = 0,
  .is_failure = 0
};
