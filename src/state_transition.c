#include <state_transition.h>

#include <memory.h>

/*
 * ****************************************************************************
 */

void state_transition_init_defaults ( state_transition_desc_t* transition_ptr )
{
  if ( transition_ptr )
  {
    memset ( transition_ptr, 0x00, sizeof ( *transition_ptr ) );
  }
}

/*
 * ****************************************************************************
 */

void state_transition_init (
  state_transition_desc_t* transition_ptr,
  transition_cb_t condition,
  custom_state_name_enum_t from,
  custom_state_name_enum_t to
)
{
  if ( transition_ptr )
  {
    state_transition_init_defaults ( transition_ptr );

    transition_ptr->condition = condition;
    transition_ptr->from = from;
    transition_ptr->to = to;
  }
}

/*
 * ****************************************************************************
 */

int needs_state_transition ( state_transition_desc_t* transition_ptr )
{
  return transition_ptr && transition_ptr->from && transition_ptr->to && transition_ptr->condition
         ? ( transition_ptr->condition ( transition_ptr->from, transition_ptr->to ) )
         : 0;
}
