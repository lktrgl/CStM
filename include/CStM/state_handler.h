#ifndef STATE_HANDLER_H_INCLUDED
#define STATE_HANDLER_H_INCLUDED

typedef void ( *handler_callback_t ) ( void* data );

typedef struct state_handler_desc_tag
{
  const handler_callback_t enter;
  const handler_callback_t run;
  const handler_callback_t leave;
} state_handler_desc_t;

#endif /* STATE_HANDLER_H_INCLUDED */
