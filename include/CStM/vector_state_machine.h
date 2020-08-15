#ifndef VECTOR_STATE_MACHINE_H_INCLUDED
#define VECTOR_STATE_MACHINE_H_INCLUDED

#include <CStM/state_machine.h>

#include <stdint.h>

/*---------------------------------------------------------------------------*/

typedef struct vector_state_diagram_desc_tag
{
  state_diagram_desc_t** diagrams;
  const uint8_t diagrams_count;
} vector_state_diagram_desc_t;

/*---------------------------------------------------------------------------*/

void run_vector_state_machine ( vector_state_diagram_desc_t* vector_machine );

#endif /* VECTOR_STATE_MACHINE_H_INCLUDED */
