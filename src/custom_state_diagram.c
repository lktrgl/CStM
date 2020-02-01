#include <custom_state_diagram.h>
#include <custom_state_initial.h>

#include <state_node.h>

#include <stddef.h>

const state_node_desc_t* custom_nodes[] =
{
  &custom_state_initial
};

state_diagram_desc_t custom_state_diagram =
{
  .current_state = &custom_state_initial,
  .states = custom_nodes,
  .states_count = sizeof ( custom_nodes ) / sizeof ( custom_nodes[0] )
};
