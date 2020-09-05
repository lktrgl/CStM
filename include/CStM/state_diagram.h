#ifndef INCLUDE_CSTM_STATE_DIAGRAM_H_
#define INCLUDE_CSTM_STATE_DIAGRAM_H_

#include <CStM/state_node.h>

#include <stdint.h>

/*---------------------------------------------------------------------------*/

typedef struct state_diagram_desc_tag
{
  const state_node_desc_t* current_state;

  const state_node_desc_t** states;
  const uint8_t states_count;
} state_diagram_desc_t;

/*---------------------------------------------------------------------------*/

#endif /* INCLUDE_CSTM_STATE_DIAGRAM_H_ */
