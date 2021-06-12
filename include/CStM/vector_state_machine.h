#ifndef VECTOR_STATE_MACHINE_H_INCLUDED
#define VECTOR_STATE_MACHINE_H_INCLUDED

#include <CStM/state_diagram.h>

#include <stdint.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*/

typedef struct vector_state_diagram_desc_tag
{
  state_diagram_desc_t** diagrams;
  const uint8_t diagrams_count;
} vector_state_diagram_desc_t;

/*---------------------------------------------------------------------------*/

void init_vector_state_machine ( vector_state_diagram_desc_t* vector_machine );

/*---------------------------------------------------------------------------*/

void run_vector_state_machine ( vector_state_diagram_desc_t* vector_machine );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/*---------------------------------------------------------------------------*/

#endif /* VECTOR_STATE_MACHINE_H_INCLUDED */
