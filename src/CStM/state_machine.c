#include <CStM/state_machine.h>
#include <CStM/state_cfg.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

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

      if ( diagram->current_state->state_handler )
      {
        LGGM_PRINT_MSG_C ( 0, "Do state handlers" );

        const state_node_desc_t* current_state = diagram->current_state;
        const state_handler_desc_t* state = current_state->state_handler;
        void* data = current_state->data;

        if ( state->enter )
        {
          LGGM_PRINT_MSG_C ( 0, "Do enter state handler" );

          state->enter ( data );
        }

        uint8_t keep_state = 1;

        do
        {
          LGGM_PRINT_MSG_C ( 0, "Do loop state" );

          if ( state->input )
          {
            LGGM_PRINT_MSG_C ( 0, "Do input state handler" );

            state->input ( data );
          }

          if ( state->run )
          {
            LGGM_PRINT_MSG_C ( 0, "Do run state handler" );

            state->run ( data );
          }

          if ( state->output )
          {
            LGGM_PRINT_MSG_C ( 0, "Do output state handler" );

            state->output ( data );
          }

          if ( current_state->transitions )
          {
            LGGM_PRINT_MSG_C ( 0, "Do state transitions" );

            const state_transition_desc_t** transition = current_state->transitions;

            for ( uint8_t i = 0; *transition && i < current_state->transitions_count; ++i, ++transition )
            {
              LGGM_PRINT_MSG_C ( 0, "Do check transition" );

              if ( ( *transition )->is_transition && ( *transition )->is_transition ( data ) )
              {
                keep_state = 0;

                if ( ( *transition )->next_state_node_index < diagram->states_count )
                {
                  LGGM_PRINT_MSG_C ( 1, "Do change state" );

                  diagram->current_state = diagram->states[ ( *transition )->next_state_node_index];

                  LGGM_PRINT_INT_C ( 1, ( *transition )->next_state_node_index );
                }
                else
                {
                  LGGM_PRINT_MSG_C ( 0, "Do exit state machine" );

                  diagram->current_state = NULL;
                }

                break;
              }
            }

          } /* if ( current_state->transitions ) */
        }
        while ( keep_state );

        if ( state->leave )
        {
          LGGM_PRINT_MSG_C ( 0, "Do leave state handler" );

          state->leave ( data );
        }

      } /* if ( diagram->current_state->state_handler ) */
      else
      {
        LGGM_PRINT_MSG_C ( 1, "state_handler is NULL; stopping the diagram." );

        break;
      }

    } /* while ( diagram->current_state ) */

  } /* if ( diagram ) */

  LGGM_CALL_OUT_C ( 1 );
}
