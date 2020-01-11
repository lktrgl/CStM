#include <memory.h>
#include <stdio.h>


#include <state.h>
#include <transition.h>

typedef struct vent_status_tag
{
  int is_failed;

} vent_status_t;

static vent_status_t s_vent;

static state_desc_t s_power_on;
static state_desc_t s_vent_on_first_time;
static state_desc_t s_vent_off;
static state_desc_t s_vent_on_dark_room;
static state_desc_t s_vent_on_wet_room;
static state_desc_t s_vent_fail;

static int s_handler_init_hw ( void* p )
{
  ( void ) p;

  /*
   * init HW here
   */

  return 1;
}

static int s_handler_delay_first_vent_on ( void* p )
{
  ( void ) p;

  /*
   * sleep here for N seconds
   */

  return 1;
}

static int s_handler_delay_dark_room ( void* p )
{
  ( void ) p;

  /*
   * sleep here for N seconds
   */

  return 1;
}

static int s_handler_delay_wet_room ( void* p )
{
  ( void ) p;

  /*
   * sleep here for N seconds
   */

  return 1;
}

static int s_handler_turn_vent_on ( void* p )
{
  ( void ) p;

  /*
   * turn vent on here
   */

  return 1;
}

static int s_handler_turn_vent_off ( void* p )
{
  ( void ) p;

  /*
   * turn vent off here
   */

  return 1;
}

static void s_init_states()
{
  memset ( &s_vent, 0x00, sizeof ( s_vent ) );

  state_init (
    &s_power_on,
    &s_vent,
    NULL,
    s_handler_init_hw,
    NULL
  );

  state_init (
    &s_vent_on_first_time,
    &s_vent,
    s_handler_turn_vent_on,
    s_handler_delay_first_vent_on,
    s_handler_turn_vent_off
  );

  state_init (
    &s_vent_off,
    &s_vent,
    s_handler_turn_vent_off,
    NULL,
    NULL
  );

  state_init (
    &s_vent_on_dark_room,
    &s_vent,
    s_handler_turn_vent_on,
    s_handler_delay_dark_room,
    s_handler_turn_vent_off
  );

  state_init (
    &s_vent_on_wet_room,
    &s_vent,
    s_handler_turn_vent_on,
    s_handler_delay_wet_room,
    s_handler_turn_vent_off
  );

  state_init (
    &s_vent_fail,
    &s_vent,
    s_handler_turn_vent_off,
    NULL,
    NULL
  );
}

int main ( int argc, char** argv )
{
  ( void ) argc;
  ( void ) argv;

  s_init_states();

  printf ( "you've launched me : %s\n", argv[0] );

  return 0;
}
