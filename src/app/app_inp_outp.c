#include <app/app_inp_outp.h>

#include <app/app_cfg.h>
#include <app/app_data.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

void process_input ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;
  ( void ) app_data;

  LGGM_CALL_IN_C ( 1 );

  LGGM_PRINT_STR_C ( 1, app_data->name );

  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

void process_output ( void* data )
{
  app_data_desc_t* app_data = ( app_data_desc_t* ) data;
  ( void ) app_data;

  LGGM_CALL_IN_C ( 1 );

  LGGM_PRINT_STR_C ( 1, app_data->name );

  LGGM_CALL_OUT_C ( 1 );
}
