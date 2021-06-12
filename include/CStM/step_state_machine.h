#ifndef STEP_STATE_MACHINE_H_INCLUDED
#define STEP_STATE_MACHINE_H_INCLUDED

#include <CStM/state_diagram.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*/

void init_step_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

uint8_t run_step_state_machine ( state_diagram_desc_t* diagram );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/*---------------------------------------------------------------------------*/

#endif /* STEP_STATE_MACHINE_H_INCLUDED */
