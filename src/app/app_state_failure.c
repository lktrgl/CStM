#include <app/app_state_failure.h>

#include <app/app_cfg.h>
#include <app/app_data.h>
#include <app/app_state_init.h>
#include <app/app_states_enum.h>
#include <app/app_failure_transition.h>
#include <app/app_inp_outp.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

static void s_failure_state_run ( void* data )
{
  ( void ) data;

  LGGM_CALL_IN_C ( 1 );

  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

static const state_handler_desc_t s_failure_state_handler =
{
  .enter = NULL,
  .input = process_input,
  .run = s_failure_state_run,
  .output = process_output,
  .leave = NULL
};

/*---------------------------------------------------------------------------*/

static uint8_t s_leave_failure_state_transitition ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;

  LGGM_CALL_IN_C ( 1 );

  if ( ! app_data->has_failure )
  {
    app_data->init_done = 0;

    LGGM_CALL_OUT_C ( 1 );

    return 1;
  }
  else
  {
    LGGM_CALL_OUT_C ( 1 );

    return 0;
  }
}

/*---------------------------------------------------------------------------*/

static const state_transition_desc_t s_leave_failure_state =
{
  .is_transition = s_leave_failure_state_transitition,
  .next_state_node_index = STATE_INIT
};

/*---------------------------------------------------------------------------*/

static uint8_t s_leave_failure_singleshot_state_transitition ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;

  LGGM_CALL_IN_C ( 1 );

#if defined(APP_SINGLE_FAILURE_SHOT_ENABLED)

  if ( app_data->has_failure )
  {
    app_data->init_done = 0;

    LGGM_CALL_OUT_C ( 1 );

    return 1;
  }
  else

#endif

  {
    LGGM_CALL_OUT_C ( 1 );

    return 0;
  }
}

/*---------------------------------------------------------------------------*/

static const state_transition_desc_t s_leave_failure_singleshot_state =
{
  .is_transition = s_leave_failure_singleshot_state_transitition,
  .next_state_node_index = STATE_COUNT
};

/*---------------------------------------------------------------------------*/

static const state_transition_desc_t* s_failure_state_transitions[] =
{
  &s_leave_failure_state,
  &s_leave_failure_singleshot_state
};

/*---------------------------------------------------------------------------*/

const state_node_desc_t g_app_failure_state =
{
  .data = &g_app_data,

  .state_index = STATE_FAILURE,
  .state_handler = &s_failure_state_handler,

  .transitions = s_failure_state_transitions,
  .transitions_count = sizeof ( s_failure_state_transitions ) / sizeof ( s_failure_state_transitions[0] )
};
