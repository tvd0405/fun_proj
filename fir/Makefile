CXX = g++
CFLAG = -O3
CFLAG += -I/home/1159021/repos/fun_proj/ac_include
CFILES = fir.cpp \
	 main.cpp
COUT = fir.x

compile:
	$(CXX) $(CFLAG) $(CFILES) -o $(COUT)

run: compile
	./$(COUT)

clean:
	rm $(COUT)
