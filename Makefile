CC=g++
OBJS = main.o memorylist.o fitalgorithm.o
FLAGS = -lgtest -lgtest_main -std=c++11 -pthread

all: $(OBJS)
	$(CC) -o run $(OBJS)

main.o:  main.cpp memorylist.h
	$(CC) -c main.cpp

memorylist.o: memorylist.cpp memorylist.h fitalgorithm.h
	$(CC) -c memorylist.cpp fitalgorithm.cpp

fitalgorithm.o: fitalgorithm.cpp memoryelement.h
	$(CC) -c fitalgorithm.cpp

tests: tests.o memorylist.o fitalgorithm.o
	$(CC) -o test tests.o memorylist.o fitalgorithm.o $(FLAGS)

tests.o: tests.cpp memorylist.h
	$(CC) -c tests.cpp $(FLAGS)

clean:
	$(RM) run test *.o 

