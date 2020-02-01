#include <custom_state_initial.h>

#include <custom_state_enum.h>

#include <stddef.h>

static const state_handler_desc_t initial_state_dummy =
{
  .enter = NULL,
  .run = NULL,
  .leave = NULL
};

static uint8_t always_transit ( void* data )
{
  ( void ) data;

  return 1;
}

static const state_transition_desc_t transition_initial_dummy =
{
  .is_transition = always_transit,
  .next_state_node_index = ST_FIRST_TURN_ON
};

static const state_transition_desc_t* initial_transitions[] =
{
  &transition_initial_dummy
};

const state_node_desc_t custom_state_initial =
{
  .data = NULL,
  .state = &initial_state_dummy,
  .transitions = initial_transitions,
  .transitions_count = sizeof ( initial_transitions ) / sizeof ( initial_transitions[0] )
};
