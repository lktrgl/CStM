#include <custom_state_diagram.h>

#include <custom_state_enum.h>
#include <custom_state_data.h>
#include <custom_state_initial.h>
#include <custom_state_first_turn_on.h>
#include <custom_state_turn_off.h>
#include <custom_state_on_dark.h>
#include <custom_state_on_wet.h>
#include <custom_state_failure.h>

#include <CStM/state_node.h>

//-----------------------------------------------------------------------------

static const state_node_desc_t* state_nodes_custom[] =
{
  [ST_INITIAL] = &g_custom_state_initial,
  [ST_FIRST_TURN_ON] = &g_custom_state_first_turn_on,
  [ST_TURN_OFF] = &g_custom_state_turn_off,
  [ST_ON_DARK] = &g_custom_state_on_dark,
  [ST_ON_WET] = &g_custom_state_on_wet,
  [ST_FAILURE] = &g_custom_state_failure
};

//-----------------------------------------------------------------------------

state_diagram_desc_t g_state_diagram_custom =
{
  .current_state = &g_custom_state_initial,
  .states = state_nodes_custom,
  .states_count = sizeof ( state_nodes_custom ) / sizeof ( state_nodes_custom[0] )
};
