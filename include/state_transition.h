#ifndef STATE_TRANSITION_H_INCLUDED
#define STATE_TRANSITION_H_INCLUDED

#include <state_desc.h>
#include "custom_state_enum.h"

typedef int ( *transition_cb_t ) ( custom_state_name_enum_t from, custom_state_name_enum_t to );

typedef struct state_transition_desc_tag
{
  transition_cb_t condition;
  custom_state_name_enum_t from;
  custom_state_name_enum_t to;
} state_transition_desc_t;

void state_transition_init_defaults ( state_transition_desc_t* transition_ptr );

void state_transition_init (
  state_transition_desc_t* transition_ptr,
  transition_cb_t condition,
  custom_state_name_enum_t from,
  custom_state_name_enum_t to
);

int needs_state_transition ( state_transition_desc_t* transition_ptr );

#endif /* STATE_TRANSITION_H_INCLUDED */
