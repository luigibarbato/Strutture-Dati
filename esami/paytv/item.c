#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct programma{
	int cod;
	char titolo[20];
	char genere[20];
	int n_giorni;
	bool scaricato;
};


item newItem(int cod, char *titolo,char *genere,int n_giorni,bool scaricato){

	struct programma *p = malloc(sizeof(struct programma));

	strcpy(p->titolo,titolo);
	strcpy(p->genere,genere);
	p->cod=cod;
	p->n_giorni=n_giorni;
	p->scaricato=scaricato;

	return p;
}
int eq(item x, item y){
	if(getCod(x)==getCod(y))
		return 0;
	else
		return -1;
}
item input_item(){}
int getCod(item x){
	if(x==NULLITEM)
		return -1;

	int cod = x->cod;

	return cod;
}
bool isScaricato(item x){
	if(x==NULLITEM)
		return -1;

	bool scaricato = x->scaricato;
	return scaricato;
}
bool isDisponibile(item x){

	if(x==NULLITEM)
		return -1;

	if(x->n_giorni < 0)
		return false;
	else
		return true;
}
int decrementaGiorno(item x){
	if(x==NULLITEM)
		return -1;

	(x->n_giorni)--;
}
void setScaricato(item x,bool value){
	x->scaricato=value;
}
void output_item(item x){
printf("il titolo del programma e'%s\n", x->titolo);
printf("il genere del programma e'%s\n", x->genere);
printf("il codice del programma e'%d\n", x->cod);
printf("il numero di giorni disponibili alla visione del programma e'%d\n", x->n_giorni);
printf("il programma e' stato scaricato: %d\n", x->scaricato);
}
