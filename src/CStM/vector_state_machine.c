#include <CStM/vector_state_machine.h>
#include <CStM/state_cfg.h>
#include <CStM/step_state_machine.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

void init_vector_state_machine ( vector_state_diagram_desc_t* vector_machine )
{
  LGGM_CALL_IN_C ( 1 );

  if ( vector_machine && vector_machine->diagrams && vector_machine->diagrams_count )
  {
    LGGM_PRINT_MSG_C ( 1, "Do init vector state machine" );

    uint8_t diagram_index;

    /* initialize all the diagrams' initial state  */

    for ( diagram_index = 0; diagram_index < vector_machine->diagrams_count; ++diagram_index )
    {
      state_diagram_desc_t* current_diagram = * ( vector_machine->diagrams + diagram_index );

      init_step_state_machine ( current_diagram );

    } /* for ( diagram_index ) */
  }

  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

void run_vector_state_machine ( vector_state_diagram_desc_t* vector_machine )
{
  LGGM_CALL_IN_C ( 1 );

  if ( vector_machine && vector_machine->diagrams && vector_machine->diagrams_count )
  {
    uint8_t diagram_index;
    uint8_t keep_running = 0xFF;

    LGGM_PRINT_MSG_C ( 1, "Do run vector state machine" );

    do
    {
      /* execute all the diagrams  */

      for ( diagram_index = 0; diagram_index < vector_machine->diagrams_count; ++diagram_index )
      {
        LGGM_PRINT_MSG_C ( 0, "Do run diagram" );
        LGGM_PRINT_INT_C ( 0, diagram_index );

        state_diagram_desc_t* current_diagram = * ( vector_machine->diagrams + diagram_index );

#ifdef CSTM_CFG_CHECKED_BUILD

        if ( current_diagram )
#endif /*CSTM_CFG_CHECKED_BUILD*/
        {
          const state_node_desc_t* current_state = current_diagram->current_state;

          if ( current_state )
          {
            /*keep_running =*/ run_step_state_machine ( current_diagram );
          }
          else
          {
            LGGM_PRINT_MSG_C ( 1, "Invalid current state pointer: do exit state machine" );

            keep_running = 0x00;
          }
        } /* if ( current_diagram ) */
      } /* for ( diagram_index ) */

    }
    while ( keep_running );

  } /* if ( vector_machine && vector_machine->diagrams_count ) */

  LGGM_CALL_OUT_C ( 1 );
}
