CXX = g++
CFLAG = -O3
CFLAG += -I$(AC_INC)
CFILES = fir.cpp \
	 main.cpp
COUT = fir.x

compile:
	$(CXX) $(CFLAG) $(CFILES) -o $(COUT)

run: compile
	./$(COUT)

clean:
	rm $(COUT)
