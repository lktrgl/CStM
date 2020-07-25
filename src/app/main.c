#include <app/app_cfg.h>

#include <app/app_state_machine.h>

#include <lggm/dbgprn.h>

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  LGGM_CALL_IN();

  run_state_machine ( &g_app_state_diagram );

  LGGM_CALL_OUT();

  return 0;
}
