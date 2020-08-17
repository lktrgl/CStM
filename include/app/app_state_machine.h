#ifndef INCLUDE_APP_APP_STATE_MACHINE_H_
#define INCLUDE_APP_APP_STATE_MACHINE_H_

#include <CStM/state_machine.h>
#include <CStM/vector_state_machine.h>

extern state_diagram_desc_t g_app_state_diagram;
extern vector_state_diagram_desc_t g_app_vector_state_diagram;

/*----------------- for sample only -----------------------------------------*/

void re_init_g_app_state_diagram();

#endif /* INCLUDE_APP_APP_STATE_MACHINE_H_ */
