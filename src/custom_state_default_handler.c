#include <custom_state_default_handler.h>

#include <custom_state_enum.h>
#include <custom_state_data.h>

//-----------------------------------------------------------------------------

void turn_vent_on ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  ( void ) d;
}

//-----------------------------------------------------------------------------

void turn_vent_off ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  ( void ) d;
}

//-----------------------------------------------------------------------------

static uint8_t is_on_dark ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  if ( d->is_on_dark )
  {
    d->is_on_dark = 0;
    return 1;
  }

  return 0;
}

const state_transition_desc_t g_state_transition_on_dark =
{
  .is_transition = is_on_dark,
  .next_state_node_index = ST_ON_DARK
};

//-----------------------------------------------------------------------------

static uint8_t is_on_wet ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  if ( d->is_on_wet )
  {
    d->is_on_wet = 0;
    return 1;
  }

  return 0;
}

const state_transition_desc_t g_state_transition_on_wet =
{
  .is_transition = is_on_wet,
  .next_state_node_index = ST_ON_WET
};

//-----------------------------------------------------------------------------

static uint8_t is_failure ( void* data )
{
  custom_state_data_desc_t* d = ( custom_state_data_desc_t* ) data;

  if ( d->is_failure )
  {
    d->is_failure = 0;
    return 1;
  }

  return 0;
}

const state_transition_desc_t g_state_transition_on_failure =
{
  .is_transition = is_failure,
  .next_state_node_index = ST_FAILURE
};
