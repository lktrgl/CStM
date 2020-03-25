#include <app/app_state_machine.h>

#define DBGPRN_ENABLED
#include <trace/dbgprn.h>

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  MY_CALL_IN();

  run_state_machine ( &g_app_state_diagram );

  MY_CALL_OUT();

  return 0;
}
