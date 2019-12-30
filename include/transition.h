#ifndef TRANSITION_H_INCLUDED
#define TRANSITION_H_INCLUDED

#include <state.h>

typedef int ( *transition_cb_t ) ( state_desc_t* from, state_desc_t* to );

typedef struct transition_desc_tag
{
  transition_cb_t condition;
  state_desc_t* from;
  state_desc_t* to;
} transition_desc_t;

void transition_init_defaults ( transition_desc_t* transition_ptr );
int is_transition ( transition_desc_t* transition_ptr );

#endif /* TRANSITION_H_INCLUDED */
