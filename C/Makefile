all: main
clean:
	-rm -f main main.o
rebuild: clean all
main: main.o
	${CC} main.o -o main
main.o: main.c
	${CC} -c -std=c99 main.c
