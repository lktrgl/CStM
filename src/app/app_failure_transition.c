#include <app/app_cfg.h>

#include <app/app_failure_transition.h>
#include <app/app_data.h>
#include <app/app_states_enum.h>

#include <lggm/dbgprn.h>

static uint8_t s_failure_transitition ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;

  LGGM_CALL_IN();

  LGGM_CALL_OUT();

  return app_data->has_failure;
}

const state_transition_desc_t g_leave_on_failure =
{
  .is_transition = s_failure_transitition,
  .next_state_node_index = STATE_FAILURE
};
