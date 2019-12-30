#include <state.h>

#include <memory.h>


static int state_enter_state ( state_desc_t* state_ptr, void* param )
{
  return state_ptr
         ? state_ptr->enter_state ( param )
         : 0;
}


static int state_run ( state_desc_t* state_ptr, void* param )
{
  return state_ptr
         ? state_ptr->run ( param )
         : 0;
}


static int state_leave_state ( state_desc_t* state_ptr, void* param )
{
  return state_ptr
         ? state_ptr->leave_state ( param )
         : 0;
}

void state_init_defaults ( state_desc_t* state_ptr )
{
  memset ( state_ptr, 0x00, sizeof ( *state_ptr ) );
}

void state_do ( state_desc_t* state_ptr, state_status_t* state_status_ptr )
{
  if ( state_ptr )
  {
    if ( state_status_ptr )
    {
      state_status_ptr->enter = state_enter_state ( state_ptr, state_ptr->data_ptr );
      state_status_ptr->run = state_run ( state_ptr, state_ptr->data_ptr );
      state_status_ptr->enter = state_leave_state ( state_ptr, state_ptr->data_ptr );
    }
    else
    {
      ( void ) state_enter_state ( state_ptr, state_ptr->data_ptr );
      ( void ) state_run ( state_ptr, state_ptr->data_ptr );
      ( void ) state_leave_state ( state_ptr, state_ptr->data_ptr );
    }
  }
}



