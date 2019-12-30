#include <transition.h>

int is_transition ( transition_t* t )
{
  return t && t->from && t->to && t->condition
         ? ( t->condition ( t->from, t->to ) )
         : 0;
}
