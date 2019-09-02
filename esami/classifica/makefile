classifica.exe: classifica.o item.o ordered_set.o list.o main.o
				gcc classifica.o item.o ordered_set.o list.o main.o -o classifica.exe

classifica.o: classifica.h classifica.c
			  gcc -c classifica.c
item.o:	item.h item.c
		gcc -c item.c
ordered_set.o: ordered_set.h ordered_set.c
		gcc -c ordered_set.c
list.o: list.h list.c
		gcc -c list.c
main.o:	main.c
		gcc -c main.c