#include <state.h>
#include <transition.h>

#include <memory.h>


static int s_state_enter_state ( state_desc_t* state_ptr, void* param )
{
  return state_ptr
         ? state_ptr->enter_state ( param )
         : 0;
}


static int s_state_run ( state_desc_t* state_ptr, transition_desc_t** param_cond_z, void* param )
{
  int run_result = 0;

  if ( state_ptr )
  {
    if ( !param_cond_z )
    {
      /*
       * single shot mode
       */

      run_result = state_ptr->run ( param );
    }
    else
    {
      /*
       * run until condition appears mode
       */

      int stop_running = 0;

      do
      {
        /*
         * run one time
         */

        run_result = state_ptr->run ( param );

        /*
         * check if any of the conditions appear
         */

        transition_desc_t** cond = param_cond_z;

        do
        {
          stop_running += is_transition ( *cond );
        }
        while ( * ( ++cond ) );
      }
      while ( !stop_running );
    }
  }

  return run_result;
}


static int s_state_leave_state ( state_desc_t* state_ptr, void* param )
{
  return state_ptr
         ? state_ptr->leave_state ( param )
         : 0;
}

void state_init_defaults ( state_desc_t* state_ptr )
{
  memset ( state_ptr, 0x00, sizeof ( *state_ptr ) );
}

void state_init (
  state_desc_t* state_ptr,
  void* data_ptr,
  state_cb_t enter_handler,
  state_cb_t run_handler,
  state_cb_t leave_handler )
{
  if ( state_ptr )
  {
    state_init_defaults ( state_ptr );

    state_ptr->data_ptr = data_ptr;
    state_ptr->enter_state = enter_handler;
    state_ptr->run = run_handler;
    state_ptr->leave_state = leave_handler;
  }
}

void state_do ( state_desc_t* state_ptr, void* param_cond_z, state_status_t* state_status_ptr )
{
  if ( state_ptr )
  {
    if ( state_status_ptr )
    {
      /*
       * report the status
       */

      state_status_ptr->enter = s_state_enter_state ( state_ptr, state_ptr->data_ptr );
      state_status_ptr->run = s_state_run ( state_ptr, param_cond_z, state_ptr->data_ptr );
      state_status_ptr->enter = s_state_leave_state ( state_ptr, state_ptr->data_ptr );
    }
    else
    {
      /*
       * ignore the status
       */

      ( void ) s_state_enter_state ( state_ptr, state_ptr->data_ptr );
      ( void ) s_state_run ( state_ptr, param_cond_z, state_ptr->data_ptr );
      ( void ) s_state_leave_state ( state_ptr, state_ptr->data_ptr );
    }
  }
}



