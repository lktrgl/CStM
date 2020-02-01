#include <custom_state_failure.h>

#include <custom_state_data.h>
#include <custom_state_default_handler.h>

#include <CStM/state_default_handler.h>

#include <stddef.h>

//-----------------------------------------------------------------------------

static const state_handler_desc_t state_handler_failure =
{
  .enter = turn_vent_off,
  .run = NULL,
  .leave = NULL
};

//-----------------------------------------------------------------------------

static const state_transition_desc_t* state_transitions_failure[] =
{
  &g_state_transition_on_failure
};

//-----------------------------------------------------------------------------

const state_node_desc_t g_custom_state_failure =
{
  .data = &g_state_data,
  .state = &state_handler_failure,
  .transitions = state_transitions_failure,
  .transitions_count = sizeof ( state_transitions_failure ) / sizeof ( state_transitions_failure[0] )
};
