#include <state.h>

#include <memory.h>

void state_init_defaults ( state_t* state_ptr )
{
  memset ( state_ptr, 0x00, sizeof ( *state_ptr ) );
}

void* state_get_date_ptr ( state_t* state_ptr )
{
return state_ptr->data_ptr;
}

state_cb_t state_enter_state ( state_t* state_ptr )
{
  return state_ptr->enter_state;
}


state_cb_t state_run ( state_t* state_ptr )
{
  return state_ptr->run;
}


state_cb_t state_leave_state ( state_t* state_ptr )
{
  return state_ptr->leave_state;
}



