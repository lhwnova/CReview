family.out: main.o file.o vector.o search.o
	gcc -Wall -g main.o file.o vector.o search.o -o family.out 

main.o: main.c
	gcc -Wall -g -c main.c

file.o: file.c file.h
	gcc -Wall -g -c file.c

vector.o: vector.c vector.h
	gcc -Wall -g -c vector.c 

search.o: search.c search.h
	gcc -Wall -g -c search.c

clean:
	rm -f main.o family.out file.o vector.o search.o

