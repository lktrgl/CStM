#include <custom_state_transition.h>

#include <stddef.h>

static state_transition_desc_t s_tr_power_on_to_vent_on_first_time;
static state_transition_desc_t s_tr_vent_on_first_time_to_vent_off;
static state_transition_desc_t s_tr_vent_off_to_on_dark_room;
static state_transition_desc_t s_tr_on_dark_room_to_vent_off;
static state_transition_desc_t s_tr_vent_off_to_on_wet_room;
static state_transition_desc_t s_tr_on_wet_room_to_vent_off;

state_transition_desc_t* g_transitions[TR_COUNT] =
{
  &s_tr_power_on_to_vent_on_first_time,
  &s_tr_vent_on_first_time_to_vent_off,
  &s_tr_vent_off_to_on_dark_room,
  &s_tr_on_dark_room_to_vent_off,
  &s_tr_vent_off_to_on_wet_room,
  &s_tr_on_wet_room_to_vent_off
};

void init_custom_transitions()
{
  state_transition_init (
    &s_tr_power_on_to_vent_on_first_time,
    NULL,
    ST_POWER_ON,
    ST_VENT_ON_FIRST_TIME
  );

  state_transition_init (
    &s_tr_vent_on_first_time_to_vent_off,
    NULL,
    ST_VENT_ON_FIRST_TIME,
    ST_VENT_OFF
  );

  state_transition_init (
    &s_tr_vent_off_to_on_dark_room,
    NULL,
    ST_VENT_OFF,
    ST_VENT_ON_DARK_ROOM
  );

  state_transition_init (
    &s_tr_on_dark_room_to_vent_off,
    NULL,
    ST_VENT_ON_DARK_ROOM,
    ST_VENT_OFF
  );

  state_transition_init (
    &s_tr_vent_off_to_on_wet_room,
    NULL,
    ST_VENT_OFF,
    ST_VENT_ON_WET_ROOM
  );

  state_transition_init (
    &s_tr_on_wet_room_to_vent_off,
    NULL,
    ST_VENT_ON_WET_ROOM,
    ST_VENT_OFF
  );
}
