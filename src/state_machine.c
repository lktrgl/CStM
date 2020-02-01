#include <state_machine.h>

#include <stddef.h>

int run_state_machine ( state_diagram_desc_t* diagram )
{
  if ( diagram )
  {
    while ( diagram->current_state )
    {
      if ( diagram->current_state->state )
      {
        const state_node_desc_t* current_state = diagram->current_state;
        const state_handler_desc_t* state = current_state->state;
        void* data = current_state->data;

        if ( state->enter )
        {
          state->enter ( data );
        }

        uint8_t keep_state = 1;

        do
        {
          if ( state->run )
          {
            state->run ( data );
          }

          if ( current_state->transitions )
          {
            const state_transition_desc_t** transition = current_state->transitions;

            for ( uint8_t i = 0; *transition && i < current_state->transitions_count; ++i, ++transition )
            {
              if ( ( *transition )->is_transition ( data ) )
              {
                keep_state = 0;

                if ( ( *transition )->next_state_node_index <= diagram->states_count )
                {
                  diagram->current_state = diagram->states[ ( *transition )->next_state_node_index];
                }
                else
                {
                  diagram->current_state = NULL;
                }

                break;
              }
            }

          } // if ( current_state->transitions )
        }
        while ( keep_state );

        if ( state->leave )
        {
          state->leave ( data );
        }

      } // if ( diagram->current_state->state )

    } // while ( diagram->current_state )

  } // if ( diagram )

  return 0;
}
