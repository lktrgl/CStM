#include <CStM/state_machine.h>
#include <CStM/state_cfg.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

static void s_do_enter ( const state_node_desc_t* state )
{
  if ( state->state_handler && state->state_handler->enter )
  {
    state->state_handler->enter ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_input ( const state_node_desc_t* state )
{
  if ( state->state_handler && state->state_handler->input )
  {
    state->state_handler->input ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_run ( const state_node_desc_t* state )
{
  if ( state->state_handler && state->state_handler->run )
  {
    state->state_handler->run ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_output ( const state_node_desc_t* state )
{
  if ( state->state_handler && state->state_handler->output )
  {
    state->state_handler->output ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_leave ( const state_node_desc_t* state )
{
  if ( state->state_handler && state->state_handler->leave )
  {
    state->state_handler->leave ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static const state_transition_desc_t* s_is_condition ( const state_node_desc_t* state )
{
  if ( state->transitions )
  {
    const state_transition_desc_t** transition = state->transitions;
    void* data = state->data;

    for ( uint8_t i = 0; *transition && i < state->transitions_count; ++i, ++transition )
    {
      const state_transition_desc_t* transition_ptr = *transition;

      if ( transition_ptr->is_transition && transition_ptr->is_transition ( data ) )
      {
        return transition_ptr;
      }
    }
  }

  return NULL;
}

/*---------------------------------------------------------------------------*/

void run_state_machine ( state_diagram_desc_t* diagram )
{
  LGGM_CALL_IN_C ( 1 );

  if ( diagram )
  {
    LGGM_PRINT_MSG_C ( 0, "Do diagram" );

    while ( diagram->current_state )
    {
      LGGM_PRINT_MSG_C ( 0, "Do current state" );
      LGGM_PRINT_INT_C ( 0, diagram->current_state->state_index );

        const state_node_desc_t* current_state = diagram->current_state;

        LGGM_PRINT_MSG_C ( 0, "Do enter" );

        s_do_enter ( current_state );

        uint8_t do_run = 1;

        do
        {
          LGGM_PRINT_MSG_C ( 0, "Do run" );

          s_do_input ( current_state );
          s_do_run ( current_state );
          s_do_output ( current_state );

          const state_transition_desc_t* signaled_transition = s_is_condition ( current_state );

          if ( signaled_transition )
          {
            if ( signaled_transition->next_state_node_index < diagram->states_count )
            {
              LGGM_PRINT_MSG_C ( 1, "Do change state" );

              diagram->current_state = diagram->states[signaled_transition->next_state_node_index];

              LGGM_PRINT_MSG_C ( 0, "Do leave" );

              s_do_leave ( current_state );

              LGGM_PRINT_MSG_C ( 0, "Do enter" );

              s_do_enter ( diagram->current_state );
            }
            else
            {
              LGGM_PRINT_MSG_C ( 1, "Nonexistent state index: do exit state machine" );
              diagram->current_state = NULL;

              LGGM_PRINT_MSG_C ( 0, "Do leave" );

              s_do_leave ( current_state );

              do_run = 0x00;
            }
          } /* if ( signaled_transition ) */
        }
        while ( do_run );

    } /* while ( diagram->current_state ) */

  } /* if ( diagram ) */

  LGGM_CALL_OUT_C ( 1 );
}
