#ifndef STATE_MACHINE_H_INCLUDED
#define STATE_MACHINE_H_INCLUDED

#include <CStM/state_diagram.h>

/*---------------------------------------------------------------------------*/

void init_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

void run_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

#endif /* STATE_MACHINE_H_INCLUDED */
