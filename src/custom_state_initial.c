#include <custom_state_initial.h>

#include <custom_state_enum.h>
#include <custom_state_data.h>
#include <custom_state_default_handler.h>

#include <CStM/state_default_handler.h>

#include <stddef.h>

//-----------------------------------------------------------------------------

static void init_hardware ( void* data )
{
  ( void ) data;
}

static const state_handler_desc_t state_handler_initial =
{
  .enter = NULL,
  .run = init_hardware,
  .leave = NULL
};

//-----------------------------------------------------------------------------

static const state_transition_desc_t state_transition_initial =
{
  .is_transition = transit_always,
  .next_state_node_index = ST_FIRST_TURN_ON
};

static const state_transition_desc_t* state_transitions_initial[] =
{
  &g_state_transition_on_failure,
  &state_transition_initial
};

//-----------------------------------------------------------------------------

const state_node_desc_t g_custom_state_initial =
{
  .data = &g_state_data,
  .state = &state_handler_initial,
  .transitions = state_transitions_initial,
  .transitions_count = sizeof ( state_transitions_initial ) / sizeof ( state_transitions_initial[0] )
};
