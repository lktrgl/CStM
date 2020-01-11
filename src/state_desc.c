#include <state_desc.h>

#include <memory.h>

void state_init_defaults ( state_desc_t* state_ptr )
{
  if ( state_ptr )
  {
    memset ( state_ptr, 0x00, sizeof ( *state_ptr ) );
  }
}

void state_init (
  state_desc_t* state_ptr,
  void* data_ptr,
  state_cb_t enter_handler,
  state_cb_t run_handler,
  state_cb_t leave_handler
)
{
  if ( state_ptr )
  {
    state_init_defaults ( state_ptr );

    state_ptr->data_ptr = data_ptr;

    state_handler_init (
      &state_ptr->handler,
      enter_handler,
      run_handler,
      leave_handler
    );
  }
}
