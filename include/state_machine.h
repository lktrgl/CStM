#ifndef STATE_MACHINE_H_INCLUDED
#define STATE_MACHINE_H_INCLUDED

#include <state_node.h>

typedef struct state_machine_desc_tag
{
  state_node_desc_t* current_state;
  unsigned int state_count;
  state_node_desc_t* states;
} state_machine_desc_t;

void state_machine_init_defaults ( state_machine_desc_t* state_machine_ptr );

void state_machine_init (
  state_machine_desc_t* state_machine_ptr,
  state_node_desc_t* initial_state_ptr
);

void state_machine_do (
  state_machine_desc_t* state_machine_ptr
);

#endif /* STATE_MACHINE_H_INCLUDED */
