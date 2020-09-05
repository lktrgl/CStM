#ifndef STEP_STATE_MACHINE_H_INCLUDED
#define STEP_STATE_MACHINE_H_INCLUDED

#include <CStM/state_diagram.h>

/*---------------------------------------------------------------------------*/

void init_step_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

uint8_t run_step_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

#endif /* STEP_STATE_MACHINE_H_INCLUDED */
