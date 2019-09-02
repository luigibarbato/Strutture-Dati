#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct squadra{
	char nome[20];
	int punteggio;
	int n_partite;
	int n_segnati;
	int n_subiti;
};

item newItem(char *nome,int punteggio,int n_partite,int n_segnati,int n_subiti){

	struct squadra *i = malloc(sizeof(struct squadra));
	strcpy(i->nome,nome);
	i->punteggio=punteggio;
	i->n_partite=n_partite;
	i->n_segnati=n_segnati;
	i->n_subiti=n_subiti;
	return i;
}
int cmpItem(item x,item y){
	int res = strcmp(x->nome,y->nome);
	return res;
}
int eq(item x, item y){
	int res = strcmp(getNome(x),getNome(y));

	return res;
}
item input_item(){}
void output_item(item x){
	printf("La squadra ha come nome: %s\n", x->nome);
	printf("La squadra ha come punteggio: %d\n", x->punteggio );
	printf("La squadra ha come partite fatte: %d\n", x->n_partite);
	printf("La squadra ha come goal segnati: %d\n", x->n_segnati);
	printf("La squadra ha come goal subiti: %d\n", x->n_subiti);
}
char *getNome(item x){
	char *str = malloc(sizeof(char)*20);

	strcpy(str,x->nome);

	return str;
}