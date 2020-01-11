#include <custom_state_handler.h>

#include <state_node.h>

#include <memory.h>

static vent_status_t s_vent_status;

static state_handler_desc_t s_st_power_on;
static state_handler_desc_t s_st_vent_on_first_time;
static state_handler_desc_t s_st_vent_off;
static state_handler_desc_t s_st_vent_on_dark_room;
static state_handler_desc_t s_st_vent_on_wet_room;
static state_handler_desc_t s_st_vent_fail;


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


void init_custom_handlers()
{
  memset ( &s_vent_status, 0x00, sizeof ( s_vent_status ) );

  state_handler_init (
    &s_st_power_on,
    NULL,
    s_handler_init_hw,
    NULL
  );

  state_handler_init (
    &s_st_vent_on_first_time,
    s_handler_turn_vent_on,
    s_handler_delay_first_vent_on,
    s_handler_turn_vent_off
  );

  state_handler_init (
    &s_st_vent_off,
    s_handler_turn_vent_off,
    NULL,
    NULL
  );

  state_handler_init (
    &s_st_vent_on_dark_room,
    s_handler_turn_vent_on,
    s_handler_delay_dark_room,
    s_handler_turn_vent_off
  );

  state_handler_init (
    &s_st_vent_on_wet_room,
    s_handler_turn_vent_on,
    s_handler_delay_wet_room,
    s_handler_turn_vent_off
  );

  state_handler_init (
    &s_st_vent_fail,
    s_handler_turn_vent_off,
    NULL,
    NULL
  );
}

