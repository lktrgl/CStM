#include <custom_state_turn_off.h>

#include <custom_state_data.h>
#include <custom_state_default_handler.h>

#include <CStM/state_default_handler.h>

#include <stddef.h>

//-----------------------------------------------------------------------------

static void sleep_until_any_event ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  ( void ) d;

  // sleep for (d->delay_on_turn_off) seconds
}

static const state_handler_desc_t state_handler_turn_off =
{
  .enter = turn_vent_off,
  .run = sleep_until_any_event,
  .leave = NULL
};

//-----------------------------------------------------------------------------

static const state_transition_desc_t* state_transitions_turn_off[] =
{
  &g_state_transition_on_failure,
  &g_state_transition_on_wet,
  &g_state_transition_on_dark
};

//-----------------------------------------------------------------------------

const state_node_desc_t g_custom_state_turn_off =
{
  .data = &g_state_data,
  .state = &state_handler_turn_off,
  .transitions = state_transitions_turn_off,
  .transitions_count = sizeof ( state_transitions_turn_off ) / sizeof ( state_transitions_turn_off[0] )
};

