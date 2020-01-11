#ifndef CUSTOM_STATE_TRANSITION_H_INCLUDED
#define CUSTOM_STATE_TRANSITION_H_INCLUDED

#include <state_transition.h>

#include <custom_transition_enum.h>

void init_custom_transitions();

extern state_transition_desc_t* g_transitions[TR_COUNT];

#endif /* CUSTOM_STATE_TRANSITION_H_INCLUDED */
