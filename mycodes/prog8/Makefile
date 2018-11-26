family.out: main.o vector.o file.o
	gcc -Wall -g -o family.out vector.o file.o main.o

main.o: main.c main.h file.h vector.h search.h
	gcc -Wall -g -c main.c

vector.o: vector.c vector.h
	gcc -Wall -g -c vector.c

file.o: file.c file.h vector.h
	gcc -Wall -g -c file.c

search.o: search.c search.h 
	gcc -Wall -g -c search.c

clean: 
	rm -f family.out main.o vector.o file.o search.o