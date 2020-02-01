#include <custom_state_on_dark.h>

#include <custom_state_enum.h>
#include <custom_state_data.h>
#include <custom_state_default_handler.h>

#include <CStM/state_default_handler.h>

#include <stddef.h>

//-----------------------------------------------------------------------------

static void sleep_until_on_dark ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  ( void ) d;

  // sleep for (d->delay_on_dark) seconds
}

static const state_handler_desc_t state_handler_on_dark =
{
  .enter = turn_vent_on,
  .run = sleep_until_on_dark,
  .leave = turn_vent_off
};

//-----------------------------------------------------------------------------

static const state_transition_desc_t* state_transitions_on_dark[] =
{
  &g_state_transition_on_failure,
  &g_state_transition_on_wet,
  &g_state_transition_to_off
};

//-----------------------------------------------------------------------------

const state_node_desc_t g_custom_state_on_dark =
{
  .data = &g_state_data,
  .state = &state_handler_on_dark,
  .transitions = state_transitions_on_dark,
  .transitions_count = sizeof ( state_transitions_on_dark ) / sizeof ( state_transitions_on_dark[0] )
};
