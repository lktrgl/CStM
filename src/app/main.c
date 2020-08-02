#include <app/app_cfg.h>

#include <app/app_state_machine.h>

#include <lggm/dbgprn.h>

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  LGGM_CALL_IN_C ( 0 );

  run_state_machine ( &g_app_state_diagram );

  LGGM_CALL_OUT_C ( 0 );

  return 0;
}
