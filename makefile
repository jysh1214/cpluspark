.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/ut_test $(BIN)/main

$(BIN)/ut_test: $(TEST)/ut_test.cpp\
	$(OBJ)/parser.o\
	$(OBJ)/data_frame.o
	g++ -Wall -g -std=c++17 $^ -o $@ $(LIBS)

$(BIN)/main: main.cpp\
	$(OBJ)/parser.o\
	$(OBJ)/data_frame.o
	g++ -Wall -g -std=c++17 $^ -o $@ $(LIBS)

$(OBJ)/parser.o: $(SRC)/parser.cpp $(SRC)/parser.h
	g++ -Wall -g -std=c++17 -c $< -o $@

$(OBJ)/data_frame.o: $(SRC)/data_frame.cpp $(SRC)/data_frame.h
	g++ -Wall -g -std=c++17 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ) .vscode

state:
	wc src/* test/*