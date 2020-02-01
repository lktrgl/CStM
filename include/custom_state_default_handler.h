#ifndef CUSTOM_STATE_DEFAULT_HANDLER_H_INCLUDED
#define CUSTOM_STATE_DEFAULT_HANDLER_H_INCLUDED

#include <state_transition.h>

void turn_vent_on ( void* data );
void turn_vent_off ( void* data );

extern const state_transition_desc_t g_state_transition_on_dark;
extern const state_transition_desc_t g_state_transition_on_wet;
extern const state_transition_desc_t g_state_transition_on_failure;
extern const state_transition_desc_t g_state_transition_to_off;

#endif /* CUSTOM_STATE_DEFAULT_HANDLER_H_INCLUDED */
