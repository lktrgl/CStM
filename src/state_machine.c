#include <state_machine.h>

#include <memory.h>

/*
 * ****************************************************************************
 */

void state_machine_init_defaults ( state_machine_desc_t* state_machine_ptr )
{
  if ( state_machine_ptr )
  {
    memset ( state_machine_ptr, 0x00, sizeof ( *state_machine_ptr ) );
  }
}

/*
 * ****************************************************************************
 */

void state_machine_init (
  state_machine_desc_t* state_machine_ptr,
  state_node_desc_t* initial_state_ptr
)
{
  if ( state_machine_ptr )
  {
    state_machine_init_defaults ( state_machine_ptr );
    state_machine_ptr->current_state = initial_state_ptr;
  }
}

/*
 * ****************************************************************************
 */

void state_machine_do ( state_machine_desc_t* state_machine_ptr )
{
  if ( state_machine_ptr && state_machine_ptr->current_state )
  {
    state_status_t* ss = &state_machine_ptr->current_state->state.status;
    void* data = state_machine_ptr->current_state->state.data_ptr;
    state_handler_desc_t* sh = &state_machine_ptr->current_state->state.handler;

    ss->enter = sh->enter_state ( data );

    int continue_running = 0;

    do
    {
      ss->run = sh->run ( data );

      state_transition_desc_t** st = state_machine_ptr->current_state->condition;

      if ( ( continue_running = !! st ) )
      {
        for ( /*EMPRY*/; *st; ++st )
        {
          if ( needs_state_transition ( *st ) )
          {
            continue_running = 0;

            //            ( *st )->to

            break;
          }
        }
      }
    }
    while ( continue_running );

    ss->leave = sh->leave_state ( data );
  }
}
