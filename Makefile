CC=g++
OBJS = main.o memorylist.o scheduler.o
FLAGS = -lgtest -lgtest_main -std=c++11 -pthread

build: $(OBJS)
	$(CC) -o run $(OBJS)

main.o:  main.cpp memorylist.h
	$(CC) -c main.cpp

memorylist.o: memorylist.cpp memorylist.h scheduler.h
	$(CC) -c memorylist.cpp scheduler.cpp

scheduler.o: scheduler.cpp memoryelement.h
	$(CC) -c scheduler.cpp

tests: tests.o memorylist.o scheduler.o
	$(CC) -o test tests.o memorylist.o scheduler.o $(FLAGS)

tests.o: tests.cpp memorylist.h
	$(CC) -c tests.cpp $(FLAGS)

clean:
	$(RM) run test *.o 

