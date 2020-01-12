.PHONY: clean dirs

OBJ=obj
BIN=bin
SRC=../../src

all: dirs ./selectCol

./selectCol: selectCol.cpp\
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
	rm -rf $(OBJ) selectCol .vscode

state:
	wc src/*