CXX = g++
CFLAG = -O3
CFLAG += -I../ac_include
CFILES = fir.cpp \
	 main.cpp
COUT = fir.x
DOUT = output.dat

$(COUT): $(CFILES)
	$(CXX) $(CFLAG) $(CFILES) -o $(COUT)

$(DOUT): $(COUT)
	./$(COUT)

clean:
	rm $(COUT) $(DOUT)
