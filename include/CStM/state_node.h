#ifndef STATE_NODE_H_INCLUDED
#define STATE_NODE_H_INCLUDED

#include <CStM/state_handler.h>
#include <CStM/state_transition.h>

#include <stdint.h>

typedef struct state_node_desc_tag
{
  void* data;

  const state_handler_desc_t* state_handler;

  const state_transition_desc_t** transitions;
  const uint8_t transitions_count;
} state_node_desc_t;

#endif /* STATE_NODE_H_INCLUDED */
