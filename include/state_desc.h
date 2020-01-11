#ifndef STATE_DESC_H_INCLUDED
#define STATE_DESC_H_INCLUDED

#include <state_handler.h>

typedef struct state_status_tag
{
  int enter;
  int run;
  int leave;
} state_status_t;

typedef struct state_desc_tag
{
  state_status_t status;
  void* data_ptr;
  state_handler_desc_t handler;
} state_desc_t;

void state_init_defaults ( state_desc_t* state_ptr );

void state_init (
  state_desc_t* state_ptr,
  void* data_ptr,
  state_cb_t enter_handler,
  state_cb_t run_handler,
  state_cb_t leave_handler
);

#endif /* STATE_DESC_H_INCLUDED */
