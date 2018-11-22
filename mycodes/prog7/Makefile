family.out: main.o file.o vector.o search.o
	gcc -Wall -g -o family.out main.o file.o vector.o search.o

file.o: file.c file.h
	gcc -Wall -g -c file.c

main.o: main.c file.h vector.h
	gcc -Wall -g -c main.c

vector.o: vector.c vector.h
	gcc -Wall -g -c vector.c

search.o: search.c search.h
	gcc -Wall -g -c search.c

clean:
	rm -f family.out main.o file.o vector.o search.0