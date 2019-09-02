#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
struct prodotto{
	int id;
	char descr[20];
	int prezzo;
	int offerta;
	int scad;
	storico store;
};

item newItem(int id,char descr[20],int prezzo,int offerta,int scad){
	struct prodotto *i = malloc(sizeof(struct prodotto));

	strcpy(i->descr,descr);
	i->id=id;
	i->prezzo=prezzo;
	i->offerta=offerta;
	i->scad=scad;

	return i;
}

int eq(item x, item y){
	return(x->id==y->id);
}
int getCod(item x){
	int y = x->id;
	return y;
}
int getScad(item x){
	int y = x->scad;
	return y;
}
int getOfferta(item x){
	int y = x->offerta;
	return y;
}
int setOfferta(item x, int off){
if(x==NULLITEM)
	return -1;

x->offerta=off;
return 0;
}
item input_item(){
}

storico getStorico(item x){

	return x->store;
}
void output_item(item x){
	printf("Il codice del prodotto e': %d\n", x->id);
	printf("Il prezzo del prodotto e': %d\n", x->prezzo);
	printf("l'offerta del prodotto e': %d\n", x->offerta);
	printf("la scadenza del prodotto e': %d\n", x->scad);
	printf("La descrizione del prodotto e': %s\n", x->descr);
}