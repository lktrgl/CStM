#include <stdio.h>

#include <custom_state_enum.h>
#include <custom_state_handler.h>
#include <custom_state_transition.h>

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  init_custom_handlers();
  init_custom_transitions();

  printf ( "you've launched me : %s\n", argv[0] );

  return 0;
}
