#include <CStM/step_state_machine.h>
#include <CStM/state_cfg.h>

#include <stddef.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

static void s_do_enter ( const state_node_desc_t* state )
{
  if ( state->state_handler->enter )
  {
    state->state_handler->enter ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_input ( const state_node_desc_t* state )
{
  if ( state->state_handler->input )
  {
    state->state_handler->input ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_run ( const state_node_desc_t* state )
{
  if ( state->state_handler->run )
  {
    state->state_handler->run ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_output ( const state_node_desc_t* state )
{
  if ( state->state_handler->output )
  {
    state->state_handler->output ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static void s_do_leave ( const state_node_desc_t* state )
{
  if ( state->state_handler->leave )
  {
    state->state_handler->leave ( state->data );
  }
}

/*---------------------------------------------------------------------------*/

static const state_transition_desc_t* s_is_condition ( const state_node_desc_t* state )
{
  if ( state->transitions )
  {
    const state_transition_desc_t** transition = state->transitions;
    void* data = state->data;

    for ( uint8_t i = 0; *transition && i < state->transitions_count; ++i, ++transition )
    {
      const state_transition_desc_t* transition_ptr = *transition;

      if ( transition_ptr->is_transition && transition_ptr->is_transition ( data ) )
      {
        return transition_ptr;
      }
    }
  }

  return NULL;
}

/*---------------------------------------------------------------------------*/

void init_step_state_machine ( state_diagram_desc_t* diagram )
{
  LGGM_CALL_IN_C ( 1 );

  if ( diagram )
  {
    LGGM_PRINT_MSG_C ( 0, "Do diagram" );

    const state_node_desc_t* current_state = diagram->current_state;

#ifdef CSTM_CFG_CHECKED_BUILD_ENABLED

    if ( current_state )
#endif /*CSTM_CFG_CHECKED_BUILD_ENABLED*/
    {
      LGGM_PRINT_MSG_C ( 0, "Do enter" );

#ifdef CSTM_CFG_ON_ENTER_STATE_ENABLED
      s_do_enter ( current_state );
#endif /*CSTM_CFG_ON_ENTER_STATE_ENABLED*/
    }
  }

  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

uint8_t run_step_state_machine ( state_diagram_desc_t* diagram )
{
  LGGM_CALL_IN_C ( 0 );

  uint8_t do_run = 1;

  if ( diagram )
  {
    LGGM_PRINT_MSG_C ( 0, "Do diagram" );

    if ( diagram->current_state && diagram->current_state->state_handler )
    {
      LGGM_PRINT_MSG_C ( 0, "Do current state" );
      LGGM_PRINT_INT_C ( 0, diagram->current_state->state_index );

      const state_node_desc_t* current_state = diagram->current_state;

      LGGM_PRINT_MSG_C ( 0, "Do run" );

#ifdef CSTM_CFG_GET_INPUT_ENABLED
      s_do_input ( current_state );
#endif /*CSTM_CFG_GET_INPUT_ENABLED*/

      s_do_run ( current_state );

#ifdef CSTM_CFG_SET_OUTPUT_ENABLED
      s_do_output ( current_state );
#endif /*CSTM_CFG_SET_OUTPUT_ENABLED*/

      const state_transition_desc_t* signaled_transition = s_is_condition ( current_state );

      if ( signaled_transition )
      {
        do_run = 0x00;

        if ( signaled_transition->next_state_node_index < diagram->states_count )
        {
          LGGM_PRINT_MSG_C ( 1, "Do change state" );

          diagram->current_state = diagram->states[signaled_transition->next_state_node_index];

          LGGM_PRINT_MSG_C ( 0, "Do leave" );

#ifdef CSTM_CFG_ON_LEAVE_STATE_ENABLED
          s_do_leave ( current_state );
#endif /*CSTM_CFG_ON_LEAVE_STATE_ENABLED*/

          LGGM_PRINT_MSG_C ( 0, "Do enter" );

#ifdef CSTM_CFG_ON_ENTER_STATE_ENABLED
          s_do_enter ( diagram->current_state );
#endif /*CSTM_CFG_ON_ENTER_STATE_ENABLED*/
        }
        else
        {
          LGGM_PRINT_MSG_C ( 1, "Nonexistent state index: do exit state machine" );
          diagram->current_state = NULL;

          LGGM_PRINT_MSG_C ( 0, "Do leave" );

#ifdef CSTM_CFG_ON_LEAVE_STATE_ENABLED
          s_do_leave ( current_state );
#endif /*CSTM_CFG_ON_LEAVE_STATE_ENABLED*/
        }
      } /* if ( signaled_transition ) */

    } /* if ( diagram->current_state ) */

  } /* if ( diagram ) */

  LGGM_CALL_OUT_C ( 0 );

  return do_run;
}
