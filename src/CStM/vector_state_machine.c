#include <CStM/vector_state_machine.h>
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

void run_vector_state_machine ( vector_state_diagram_desc_t* vector_machine )
{
  LGGM_CALL_IN_C ( 1 );

  if ( vector_machine && vector_machine->diagrams && vector_machine->diagrams_count )
  {
    LGGM_PRINT_MSG_C ( 1, "Do init vector state machine" );

    uint8_t diagram_index;
    uint8_t keep_running = 0xFF;

    /* initialize all the diagrams' initial state  */

    for ( diagram_index = 0; diagram_index < vector_machine->diagrams_count; ++diagram_index )
    {
      state_diagram_desc_t* current_diagram = * ( vector_machine->diagrams + diagram_index );

      if ( current_diagram && current_diagram->current_state )
      {
        LGGM_PRINT_MSG_C ( 0, "Do enter" );

        s_do_enter ( current_diagram->current_state );
      }
    } /* for ( diagram_index ) */

    LGGM_PRINT_MSG_C ( 1, "Do run vector state machine" );

    do
    {
      /* execute all the diagrams  */

      for ( diagram_index = 0; diagram_index < vector_machine->diagrams_count; ++diagram_index )
      {
        LGGM_PRINT_MSG_C ( 0, "Do run diagram" );
        LGGM_PRINT_INT_C ( 0, diagram_index );

        state_diagram_desc_t* current_diagram = * ( vector_machine->diagrams + diagram_index );

        if ( current_diagram )
        {
          const state_node_desc_t* current_state = current_diagram->current_state;

          if ( current_state )
          {
            LGGM_PRINT_MSG_C ( 0, "Do run" );

            s_do_input ( current_state );
            s_do_run ( current_state );
            s_do_output ( current_state );

            const state_transition_desc_t* signaled_transition = s_is_condition ( current_state );

            if ( signaled_transition )
            {
              if ( signaled_transition->next_state_node_index < current_diagram->states_count )
              {
                LGGM_PRINT_MSG_C ( 1, "Do change state" );

                current_diagram->current_state = current_diagram->states[signaled_transition->next_state_node_index];

                LGGM_PRINT_MSG_C ( 0, "Do leave" );

                s_do_leave ( current_state );

                LGGM_PRINT_MSG_C ( 0, "Do enter" );

                s_do_enter ( current_diagram->current_state );
              }
              else
              {
                LGGM_PRINT_MSG_C ( 1, "Nonexistent state index: do exit state machine" );
                current_diagram->current_state = NULL;

                LGGM_PRINT_MSG_C ( 0, "Do leave" );

                s_do_leave ( current_state );

                keep_running = 0x00;
              }
            } /* if ( signaled_transition ) */
          } /* if ( current_diagram->current_state ) */
          else
          {
            LGGM_PRINT_MSG_C ( 1, "Invalid current state pointer: do exit state machine" );

            keep_running = 0x00;
          }
        } /* if ( current_diagram ) */
      } /* for ( diagram_index ) */

    } /* do */

    while ( keep_running );
  } /* if ( vector_machine && vector_machine->diagrams_count ) */

  LGGM_CALL_OUT_C ( 1 );
}
