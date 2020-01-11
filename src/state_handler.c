#include <state_handler.h>

#include <memory.h>

/*
 * ****************************************************************************
 */

void state_handler_init_defaults ( state_handler_desc_t* state_handler_ptr )
{
  if ( state_handler_ptr )
  {
    memset ( state_handler_ptr, 0x00, sizeof ( *state_handler_ptr ) );
  }
}

/*
 * ****************************************************************************
 */

void state_handler_init (
  state_handler_desc_t* state_handler_ptr,
  state_cb_t enter_handler,
  state_cb_t run_handler,
  state_cb_t leave_handler )
{
  if ( state_handler_ptr )
  {
    state_handler_init_defaults ( state_handler_ptr );

    state_handler_ptr->enter_state = enter_handler;
    state_handler_ptr->run = run_handler;
    state_handler_ptr->leave_state = leave_handler;
  }
}
