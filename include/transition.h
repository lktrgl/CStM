#ifndef TRANSITION_H_INCLUDED
#define TRANSITION_H_INCLUDED

#include <state.h>

typedef int ( *transition_cb_t ) ( state_desc_t* from, state_desc_t* to );

typedef struct transition_tag
{
  transition_cb_t condition;
  state_desc_t* from;
  state_desc_t* to;
} transition_t;

int is_transition ( transition_t* t );

#endif /* TRANSITION_H_INCLUDED */
