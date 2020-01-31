#ifndef STATE_MACHINE_H_INCLUDED
#define STATE_MACHINE_H_INCLUDED

#include <state_node.h>

#include <stdint.h>

typedef struct state_machine_desc_tag
{
  const state_node_desc_t* current_state;

  const state_node_desc_t** states;
  const uint8_t states_count;
} state_diagram_desc_t;

int run_state_machine ( state_diagram_desc_t* machine );

#endif /* STATE_MACHINE_H_INCLUDED */
