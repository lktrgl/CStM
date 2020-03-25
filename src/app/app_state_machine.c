#include <app/app_state_machine.h>
#include <app/app_state_init.h>
#include <app/app_state_work.h>
#include <app/app_state_failure.h>
#include <app/app_states_enum.h>

#include <stddef.h>

static const state_node_desc_t* s_states[STATE_COUNT] =
{
  &g_app_init_state,
  &g_app_work_state,
  &g_app_failure_state
};

state_diagram_desc_t g_app_state_diagram =
{
  .current_state = &g_app_init_state,

  .states = s_states,
  .states_count = sizeof ( s_states ) / sizeof ( s_states[0] )
};
