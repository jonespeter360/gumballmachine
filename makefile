OutputName = main
EXE = $(OutputName).out
LOG = $(OutputName).log


.PHONY = all clean build debug run

# runs the exe
run: all
	./$(EXE)

# builds the executable
all: build
	@g++ -Wall -Wextra -Werror -std=c++11 -o $(EXE) *.o #2> $(LOG)

# debugs the executable
debug: all
	gdb ./$(EXE)
	
# creates the object files
build:
	@g++ -Wall -Wextra -Werror -std=c++11 -g -c *.cpp #2> $(LOG)

# cleans out the object files
clean: 
	@rm *.o
	@rm *.out
