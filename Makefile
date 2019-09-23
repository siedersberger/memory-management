CC=g++
OBJS = main.o memorylist.o scheduler.o

build: $(OBJS)
	$(CC) -o run $(OBJS)

main.o:  main.cpp memorylist.h
	$(CC) -c main.cpp

memorylist.o: memorylist.cpp memorylist.h memoryelement.h
	$(CC) -c memorylist.cpp

scheduler.o: scheduler.cpp memoryelement.h
	$(CC) -c scheduler.cpp

clean:
	$(RM) run *.o 
