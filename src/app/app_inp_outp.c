#include <app/app_inp_outp.h>

#include <app/app_cfg.h>
#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

void process_input ( void* data )
{
  ( void ) data;

  LGGM_CALL_IN_C ( 1 );

  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

void process_output ( void* data )
{
  ( void ) data;

  LGGM_CALL_IN_C ( 1 );

  LGGM_CALL_OUT_C ( 1 );
}
