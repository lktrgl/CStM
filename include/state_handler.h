#ifndef STATE_HANDLER_H_INCLUDED
#define STATE_HANDLER_H_INCLUDED

typedef int ( *state_cb_t ) ( void* param );

typedef struct state_handler_desc_tag
{
  state_cb_t enter_state;
  state_cb_t run;
  state_cb_t leave_state;
} state_handler_desc_t;

void state_handler_init_defaults ( state_handler_desc_t* state_handler_ptr );

void state_handler_init (
  state_handler_desc_t* state_handler_ptr,
  state_cb_t enter_handler,
  state_cb_t run_handler,
  state_cb_t leave_handler
);

#endif /* STATE_HANDLER_H_INCLUDED */
