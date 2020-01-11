#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED


typedef int ( *state_cb_t ) ( void* param );

typedef struct state_status_tag
{
  int enter;
  int run;
  int leave;
} state_status_t;

typedef struct state_desc_tag
{
  void* data_ptr;
  state_cb_t enter_state;
  state_cb_t run;
  state_cb_t leave_state;
} state_desc_t;

void state_init_defaults ( state_desc_t* state_ptr );
void state_init (
  state_desc_t* state_ptr,
  void* data_ptr,
  state_cb_t enter_handler,
  state_cb_t run_handler,
  state_cb_t leave_handler
);
void state_do ( state_desc_t* state_ptr, void* param_cond_z, state_status_t* state_status_ptr );

#endif /* STATE_H_INCLUDED */
