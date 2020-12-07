CXX		:= g++
CXX_FLAGS 	:= -Wall -Wextra -std=c++2a -ggdb

BIN := bin
SRC := src
INCLUDE := include

EXEC := main

all:
	$(BIN)/$(EXEC)

run: clean all
	clear
	./$(BIN)/$(EXEC)

$(BIN)/$(EXEC): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

clean:
	rm $(BIN)/*