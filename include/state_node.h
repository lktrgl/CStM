#ifndef STATE_NODE_H_INCLUDED
#define STATE_NODE_H_INCLUDED

#include <state_handler.h>
#include <state_transition.h>

#include <stdint.h>

typedef struct state_node_desc_tag
{
  void* data;

  const state_handler_desc_t* state;

  const state_transition_desc_t** transitions;
  const uint8_t transitions_count;
} state_node_desc_t;

#endif /* STATE_NODE_H_INCLUDED */
