.PHONY: clean dirs

OBJ=obj
BIN=bin
SRC=../../src

all: dirs ./getMax_getMin

./getMax_getMin: getMax_getMin.cpp\
	$(OBJ)/parser.o\
	$(OBJ)/data_frame.o
	g++-7 -Wall -g -std=c++17 $^ -o $@

$(OBJ)/parser.o: $(SRC)/parser.cpp $(SRC)/parser.h
	g++-7 -Wall -g -std=c++17 -c $< -o $@

$(OBJ)/data_frame.o: $(SRC)/data_frame.cpp $(SRC)/data_frame.h
	g++-7 -Wall -g -std=c++17 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(OBJ)

clean:
	rm -rf $(OBJ) getMax_getMin .vscode

state:
	wc src/*