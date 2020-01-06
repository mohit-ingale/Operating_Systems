CC=gcc

main: main.o add.o sub.o mul.o
	$(CC) -o main main.o add.o sub.o mul.o
main.o:
	$(CC) -c main.c
add.o:
	$(CC) -c add.c
sub.o:
	$(CC) -c sub.c

mul.o:
	$(CC) -c mul.c

clean:
	rm -r *.o main

library:
	ar crv libarith.a add.o sub.o mul.o
