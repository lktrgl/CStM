#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED


typedef int ( *state_cb_t ) ( void* param );

typedef struct state_tag
{
  void* data_ptr;
  state_cb_t enter_state;
  state_cb_t run;
  state_cb_t leave_state;
} state_t;

void state_init_defaults ( state_t* );
void* state_get_date_ptr ( state_t* );
state_cb_t state_enter_state ( state_t* );
state_cb_t state_run ( state_t* );
state_cb_t state_leave_state ( state_t* );

#endif /* STATE_H_INCLUDED */
