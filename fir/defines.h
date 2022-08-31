#ifndef _DEFINES_H
#define _DEFINES_H

#define NTAPS 49
#define PSIZE 1
#define DW 12
#if 0
typedef double input_t;
typedef double output_t;
typedef double coef_t;
typedef double internal_t;
#else
#include "ac_fixed.h"
typedef ac_fixed<DW, 1> data_t;
typedef ac_fixed<2*DW+7, 8> int_t;
typedef data_t input_t;
typedef data_t output_t;
typedef data_t coef_t;
typedef int_t internal_t;
#endif
#endif
