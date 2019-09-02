asta.exe: asta.o item.o list.o main.o storico.o
		 gcc asta.o item.o list.o main.o storico.o -o asta.exe
asta.o:	asta.h asta.c
		gcc -c asta.c
list.o: list.h list.c
		gcc -c list.c
item.o: item.h item.c
		gcc -c item.c
storico.o: storico.h storico.c
		gcc -c storico.c