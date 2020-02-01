#include <stdio.h>
#include <custom_state_diagram.h>

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  printf ( "you've launched me : %s\n", argv[0] );

  run_state_machine ( &custom_state_diagram );

  return 0;
}
