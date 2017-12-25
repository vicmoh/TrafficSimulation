CC = gcc
CFLAGS = -Wall -pedantic -g -std=c99 -Iinclude
BIN = ./bin/
SRC = ./src/
AST = ./assets/

all: program test

program:
	$(CC) $(CFLAGS) $(SRC)main.c $(SRC)car.c $(SRC)linkList.c $(SRC)simulation.c $(SRC)dummy.c -o $(BIN)runMe

test:
	$(CC) $(CFLAGS) $(SRC)testMain.c $(SRC)car.c $(SRC)linkList.c $(SRC)simulation.c $(SRC)dummy.c -o $(BIN)runTest

runMe:
	$(BIN)runMe

runTest:
	$(BIN)runTest

clean:
	rm $(BIN)*.o $(BIN)runMe $(BIN)testMe