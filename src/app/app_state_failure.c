#include <app/app_state_failure.h>
#include <app/app_data.h>
#include <app/app_state_init.h>
#include <app/app_states_enum.h>
#include <app/app_failure_transition.h>

#include <stddef.h>

#define DBGPRN_ENABLED
#include <trace/dbgprn.h>

static void s_failure_state_run ( void* data )
{
  ( void ) data;

  MY_CALL_IN();

  MY_CALL_OUT();

}

static const state_handler_desc_t s_failure_state_handler =
{
  .enter = NULL,
  .run = s_failure_state_run,
  .leave = NULL
};

static uint8_t s_leave_failure_state_transitition ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;

  MY_CALL_IN();

  if ( ! app_data->has_failure )
  {
    app_data->init_done = 0;

    MY_CALL_OUT();

    return 1;
  }
  else
  {
    MY_CALL_OUT();

    return 0;
  }
}

static const state_transition_desc_t s_leave_failure_state =
{
  .is_transition = s_leave_failure_state_transitition,
  .next_state_node_index = STATE_INIT
};

static const state_transition_desc_t* s_failure_state_transitions[] =
{
  &g_leave_on_failure,
  &s_leave_failure_state,
};

const state_node_desc_t g_app_failure_state =
{
  .data = &g_app_data,

  .state_handler = &s_failure_state_handler,

  .transitions = s_failure_state_transitions,
  .transitions_count = sizeof ( s_failure_state_transitions ) / sizeof ( s_failure_state_transitions[0] )
};
