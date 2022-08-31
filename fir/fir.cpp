#include "defines.h"

void fir_f(input_t input[PSIZE], output_t output[PSIZE]) {
        #pragma HLS PIPELINE II=1
	const coef_t coef[NTAPS] = {
            #include "coef.dat"
	};
	//static input_t x[NTAPS];
	static input_t x[NTAPS+PSIZE-1];
	SHIFT: for (int i=0; i<PSIZE; i++) {
        #pragma HLS unroll
   	   for (int j=0; j<NTAPS+PSIZE-2; j++) {
           #pragma HLS unroll
                x[j] = x[j+1];
   	   }
   	   x[NTAPS+PSIZE-2] = input[i];
	}
   
	ACC: for (int i=0; i<PSIZE; i++) {
        #pragma HLS unroll
   	   internal_t acc = 0;
   	   ACC_IN: for (int j=0; j<NTAPS-1; j++) {
           #pragma HLS unroll
     	        acc += x[j+i] * coef[j];
   	   }
   	   output[i] = acc;
	}
}
