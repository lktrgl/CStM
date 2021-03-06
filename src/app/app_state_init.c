#include <app/app_state_init.h>

#include <app/app_cfg.h>
#include <app/app_data.h>
#include <app/app_states_enum.h>
#include <app/app_failure_transition.h>
#include <app/app_inp_outp.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

static void s_init_state_run ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;

  LGGM_CALL_IN_C ( 1 );

  LGGM_PRINT_STR_C ( 1, app_data->name );

  app_data->init_done = 1;

  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

static const state_handler_desc_t s_init_state_handler =
{
  .enter = NULL,
  .input = process_input,
  .run = s_init_state_run,
  .output = process_output,
  .leave = NULL
};

/*---------------------------------------------------------------------------*/

static uint8_t s_leave_init_state_transitition ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;

  LGGM_CALL_IN_C ( 1 );

  LGGM_PRINT_STR_C ( 1, app_data->name );

  if ( app_data->init_done && ! app_data->has_failure )
  {
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

static const state_transition_desc_t s_leave_init_state =
{
  .is_transition = s_leave_init_state_transitition,
  .next_state_node_index = STATE_WORK
};

/*---------------------------------------------------------------------------*/

static const state_transition_desc_t* s_init_state_transitions[] =
{
  &g_leave_on_failure,
  &s_leave_init_state
};

/*---------------------------------------------------------------------------*/

const state_node_desc_t g_app_init_state =
{
  .data = &g_app_data,

  .state_index = STATE_INIT,
  .state_handler = &s_init_state_handler,

  .transitions = s_init_state_transitions,
  .transitions_count = sizeof ( s_init_state_transitions ) / sizeof ( s_init_state_transitions[0] )
};

/*---------------------------------------------------------------------------*/

const state_node_desc_t g_app_init2_state =
{
  .data = &g_app_data2,

  .state_index = STATE_INIT,
  .state_handler = &s_init_state_handler,

  .transitions = s_init_state_transitions,
  .transitions_count = sizeof ( s_init_state_transitions ) / sizeof ( s_init_state_transitions[0] )
};
