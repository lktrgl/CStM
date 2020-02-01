#ifndef CUSTOM_STATE_ENUM_H_INCLUDED
#define CUSTOM_STATE_ENUM_H_INCLUDED

typedef enum custom_state_enum_tag
{
  ST_INITIAL,
  ST_FIRST_TURN_ON,
  ST_TURN_OFF,
  ST_ON_DARK,
  ST_ON_WET,
  ST_FAILURE,

  ST_COUNT
} custom_state_enum_t;

#endif /* CUSTOM_STATE_ENUM_H_INCLUDED */
