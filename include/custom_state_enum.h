#ifndef STATE_ENUM_INCLUDED
#define STATE_ENUM_INCLUDED

typedef enum custom_state_name_enum_tag
{
  ST_POWER_ON,
  ST_VENT_ON_FIRST_TIME,
  ST_VENT_OFF,
  ST_VENT_ON_DARK_ROOM,
  ST_VENT_ON_WET_ROOM,
  ST_VENT_FAIL,

  ST_COUNT
} custom_state_name_enum_t;

#endif /* STATE_ENUM_INCLUDED */
