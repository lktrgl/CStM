#include <app/app_state_machine.h>

#include <app/app_cfg.h>
#include <app/app_data.h>
#include <app/app_state_init.h>
#include <app/app_state_work.h>
#include <app/app_state_failure.h>
#include <app/app_states_enum.h>

#include <stddef.h>

/*---------------------------------------------------------------------------*/

static const state_node_desc_t* s_states[STATE_COUNT] =
{
  [STATE_INIT] = &g_app_init_state,
  [STATE_WORK] = &g_app_work_state,
  [STATE_FAILURE] = &g_app_failure_state
};

/*---------------------------------------------------------------------------*/

state_diagram_desc_t g_app_state_diagram =
{
  .current_state = &g_app_init_state,

  .states = s_states,
  .states_count = sizeof ( s_states ) / sizeof ( s_states[0] )
};

/*---------------------------------------------------------------------------*/

static const state_node_desc_t* s_states2[STATE_COUNT] =
{
  [STATE_INIT] = &g_app_init2_state,
  [STATE_WORK] = &g_app_work2_state,
  [STATE_FAILURE] = &g_app_failure2_state
};

/*---------------------------------------------------------------------------*/

static state_diagram_desc_t s_app_state_diagram2 =
{
  .current_state = &g_app_init2_state,

  .states = s_states2,
  .states_count = sizeof ( s_states ) / sizeof ( s_states[0] )
};

/*---------------------------------------------------------------------------*/

static state_diagram_desc_t* s_app_state_diagrams[] =
{
  &g_app_state_diagram,
  &s_app_state_diagram2
};

/*---------------------------------------------------------------------------*/

vector_state_diagram_desc_t g_app_vector_state_diagram =
{
  .diagrams = s_app_state_diagrams,
  .diagrams_count = sizeof ( s_app_state_diagrams ) / sizeof ( s_app_state_diagrams[0] )
};

/*---------------------------------------------------------------------------*/

void re_init_g_app_state_diagram()
{
  g_app_state_diagram.current_state = &g_app_init_state;
  ((app_data_desc_t*)g_app_state_diagram.current_state->data)->has_failure = 0;
}
