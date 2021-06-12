#ifndef STATE_MACHINE_H_INCLUDED
#define STATE_MACHINE_H_INCLUDED

#include <CStM/state_diagram.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*/

void init_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

void run_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/*---------------------------------------------------------------------------*/

#endif /* STATE_MACHINE_H_INCLUDED */
