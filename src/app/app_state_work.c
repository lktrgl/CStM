#include <app/app_state_work.h>

#include <app/app_cfg.h>
#include <app/app_data.h>
#include <app/app_states_enum.h>
#include <app/app_failure_transition.h>
#include <app/app_inp_outp.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

static void s_work_state_run ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;
  ( void ) app_data;

  LGGM_CALL_IN_C ( 1 );

#if defined(APP_SIMULATE_FAILURE_ENABLED)

  app_data->has_failure = 1;

#endif

  LGGM_CALL_OUT_C ( 1 );

}

/*---------------------------------------------------------------------------*/

static const state_handler_desc_t s_work_state_handler =
{
  .enter = NULL,
  .input = process_input,
  .run = s_work_state_run,
  .output = process_output,
  .leave = NULL
};

/*---------------------------------------------------------------------------*/

static const state_transition_desc_t* s_work_state_transitions[] =
{
  &g_leave_on_failure,
};

/*---------------------------------------------------------------------------*/

const state_node_desc_t g_app_work_state =
{
  .data = &g_app_data,

  .state_index = STATE_WORK,
  .state_handler = &s_work_state_handler,

  .transitions = s_work_state_transitions,
  .transitions_count = sizeof ( s_work_state_transitions ) / sizeof ( s_work_state_transitions[0] )
};
