#ifndef CUSTOM_STATE_HANDLER_H_INCLUDED
#define CUSTOM_STATE_HANDLER_H_INCLUDED


typedef struct vent_status_tag
{
  int is_failed;

} vent_status_t;


void init_custom_handlers();

#endif /* CUSTOM_STATE_HANDLER_H_INCLUDED */
