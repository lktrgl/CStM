#include <CStM/state_default_handler.h>
#include <CStM/state_cfg.h>

#include <trace/dbgprn.h>

//-----------------------------------------------------------------------------

uint8_t transit_always ( void* data )
{
  ( void ) data;

  MY_CALL_IN();

  MY_CALL_OUT();

  return 1;
}
