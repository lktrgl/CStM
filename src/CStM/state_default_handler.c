#include <CStM/state_default_handler.h>
#include <CStM/state_cfg.h>

#include <lggm/dbgprn.h>

//-----------------------------------------------------------------------------

uint8_t transit_always ( void* data )
{
  ( void ) data;

  LGGM_CALL_IN_C ( 0 );

  LGGM_CALL_OUT_C ( 0 );

  return 1;
}
