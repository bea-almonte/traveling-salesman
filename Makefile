CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type  -Werror=uninitialized # --coverage
# Do not allow compiling if a non-void function is missing a return statement
# Do not allow compiling if a variable is used without being initialized

OBJECTS = bruteforce.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

memory-check: 
	valgrind ./final-simulation

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* main
