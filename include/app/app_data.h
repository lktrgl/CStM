#ifndef INCLUDE_APP_APP_DATA_H_
#define INCLUDE_APP_APP_DATA_H_

#include <stdint.h>

typedef struct app_data_desc_tag
{
  uint8_t init_done;
  uint8_t has_failure;
} app_data_desc_t;

extern app_data_desc_t g_app_data;

#endif /* INCLUDE_APP_APP_DATA_H_ */
