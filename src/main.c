#include <stdio.h>
#include <custom_state_diagram.h>

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  printf ( "you've launched me : %s\n", argv[0] );

  run_state_machine ( &g_state_diagram_custom );

  return 0;
}
