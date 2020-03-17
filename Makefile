all: main
clean:
	-rm -f main
rebuild: clean all
main: main.o
	${CC} main.o -o main
main.o: main.c
	${CC} -c main.c
