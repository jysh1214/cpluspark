.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj

all: dirs $(BIN)/main

$(BIN)/main: main.cpp\
	$(OBJ)/parser.o\
	$(OBJ)/data_frame.o
	g++-7 -Wall -g -std=c++17 $^ -o $@

$(OBJ)/parser.o: $(SRC)/parser.cpp $(SRC)/parser.h
	g++-7 -Wall -g -std=c++17 -c $< -o $@

$(OBJ)/data_frame.o: $(SRC)/data_frame.cpp $(SRC)/data_frame.h
	g++-7 -Wall -g -std=c++17 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ) .vscode

state:
	wc src/* test/*