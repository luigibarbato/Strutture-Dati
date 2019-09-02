paytv.exe: main.o item.o paytv.o list.o queue.o
		  gcc  item.o paytv.o list.o queue.o main.o -o paytv.exe
item.o: item.h item.c
		gcc -c item.c
list.o: list.h list.c
		gcc -c list.c
queue.o: queue.h queue.c
		gcc -c queue.c
paytv.o: paytv.h paytv.c
		gcc -c paytv.c
main.o: main.c
		gcc -c main.c