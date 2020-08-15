#ifndef STATE_TRANSITION_H_INCLUDED
#define STATE_TRANSITION_H_INCLUDED

#include <stdint.h>

/*---------------------------------------------------------------------------*/

typedef uint8_t ( *condition_callback_t ) ( void* data );

/*---------------------------------------------------------------------------*/

typedef struct state_transition_desc_tag
{
  const condition_callback_t is_transition;
  const uint8_t next_state_node_index;
} state_transition_desc_t;

#endif /* STATE_TRANSITION_H_INCLUDED */
