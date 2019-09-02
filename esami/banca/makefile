gestore.exe: main.o item.o gestore.o queue.o
		  gcc  item.o gestore.o queue.o main.o -o gestore.exe
item.o: item.h item.c
		gcc -c item.c
queue.o: queue.h queue.c
		gcc -c queue.c
gestore.o: gestore.h gestore.c
		gcc -c gestore.c
main.o: main.c
		gcc -c main.c