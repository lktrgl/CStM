#include <custom_state_first_turn_on.h>

#include <custom_state_enum.h>
#include <custom_state_data.h>
#include <custom_state_default_handler.h>

#include <state_default_handler.h>

#include <stddef.h>

static void sleep_until_first_turn_on ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  ( void ) d;

  // sleep for (d->delay_first_time_on) seconds
}

static const state_handler_desc_t state_handler_first_turn_on =
{
  .enter = turn_vent_on,
  .run = sleep_until_first_turn_on,
  .leave = turn_vent_off
};

static const state_transition_desc_t state_transition_first_turn_on =
{
  .is_transition = transit_always,
  .next_state_node_index = ST_TURN_OFF
};

static const state_transition_desc_t* state_transitions_first_turn_on[] =
{
  &state_transition_first_turn_on
};

const state_node_desc_t g_custom_state_first_turn_on =
{
  .data = &g_state_data,
  .state = &state_handler_first_turn_on,
  .transitions = state_transitions_first_turn_on,
  .transitions_count = sizeof ( state_transitions_first_turn_on ) / sizeof ( state_transitions_first_turn_on[0] )
};

