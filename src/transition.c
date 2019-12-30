#include <transition.h>

#include <memory.h>

void transition_init_defaults ( transition_desc_t* transition_ptr )
{
  memset ( transition_ptr, 0x00, sizeof ( *transition_ptr ) );
}

int is_transition ( transition_desc_t* transition_ptr )
{
  return transition_ptr && transition_ptr->from && transition_ptr->to && transition_ptr->condition
         ? ( transition_ptr->condition ( transition_ptr->from, transition_ptr->to ) )
         : 0;
}
