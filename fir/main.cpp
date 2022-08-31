#include <fstream>
#include <iostream>
//#include <systemc.h>
using namespace std;
#include "defines.h"
//#include "fir.h"
extern void fir_f(input_t input[], output_t output[]);

int main(int argc, char *argv[]) {
	ifstream stim_f;
        stim_f.open("input.dat");

	ofstream out_f;
        out_f.open("output.dat");

	bool eof = false;
	input_t in[PSIZE];
	output_t out[PSIZE];
	int sample = 0;

	while (!eof) {
		double temp;
		stim_f >> temp; in[sample++] = temp;

		if (sample == PSIZE) {
	          fir_f(in, out);
                  for (int i=0; i<PSIZE; i++)
		     out_f << out[i] << endl;
		  sample = 0;
		}
		eof = stim_f.eof();
	}
	stim_f.close();
	out_f.close();
	return 0;
}
