#include <app/app_state_work.h>
#include <app/app_data.h>
#include <app/app_states_enum.h>
#include <app/app_failure_transition.h>
#include <app/app_cfg.h>

#include <stddef.h>

#include <trace/dbgprn.h>

static void s_work_state_run ( void* data )
{
  ( void ) data;

  MY_CALL_IN();

  MY_CALL_OUT();

}

static const state_handler_desc_t s_work_state_handler =
{
  .enter = NULL,
  .run = s_work_state_run,
  .leave = NULL
};

static const state_transition_desc_t* s_work_state_transitions[] =
{
  &g_leave_on_failure,
};

const state_node_desc_t g_app_work_state =
{
  .data = &g_app_data,

  .state_handler = &s_work_state_handler,

  .transitions = s_work_state_transitions,
  .transitions_count = sizeof ( s_work_state_transitions ) / sizeof ( s_work_state_transitions[0] )
};
