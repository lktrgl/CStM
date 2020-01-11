#ifndef STATE_NODE_H_INCLUDED
#define STATE_NODE_H_INCLUDED

#include <state_desc.h>
#include <state_transition.h>

typedef struct state_node_desc_tag
{
  state_desc_t state;
  state_transition_desc_t** condition;
} state_node_desc_t;

#endif /* STATE_NODE_H_INCLUDED */
