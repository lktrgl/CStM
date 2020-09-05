#include <CStM/state_machine.h>
#include <CStM/state_cfg.h>
#include <CStM/step_state_machine.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

void init_state_machine ( state_diagram_desc_t* diagram )
{
  LGGM_CALL_IN_C ( 1 );

  init_step_state_machine ( diagram );

  LGGM_CALL_OUT_C ( 1 );
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

      uint8_t do_run = 1;

      do
      {
        do_run = run_step_state_machine ( diagram );
      }
      while ( do_run );

    } /* while ( diagram->current_state ) */

  } /* if ( diagram ) */

  LGGM_CALL_OUT_C ( 1 );
}
