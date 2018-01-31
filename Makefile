all: application

application: application.cpp state.o county.o
	g++ application.cpp state.o county.o -o application

state.o: state.cpp state.hpp
	g++ -c state.cpp -o state.o

county.o: county.cpp county.hpp
	g++ -c county.cpp -o county.o

clean:
	rm -f *.o application
