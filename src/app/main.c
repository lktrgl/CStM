#include <app/app_cfg.h>

#include <app/app_state_machine.h>

#include <lggm/dbgprn.h>

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  LGGM_CALL_IN_C ( 1 );

  run_state_machine ( &g_app_state_diagram );

  LGGM_TRACE_C ( 1 );

  re_init_g_app_state_diagram();
  run_vector_state_machine ( &g_app_vector_state_diagram );

  LGGM_CALL_OUT_C ( 1 );

  return 0;
}
