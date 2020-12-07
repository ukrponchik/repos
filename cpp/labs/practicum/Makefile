CXX       := g++
CXX_FLAGS := -Wall -Wextra -std=c++2a -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

RECTANGLE := rect


all: $(BIN)/$(RECTANGLE)

run: clean all
	clear
	./$(BIN)/$(RECTANGLE)

$(BIN)/$(RECTANGLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

clean:
	-rm $(BIN)/*
