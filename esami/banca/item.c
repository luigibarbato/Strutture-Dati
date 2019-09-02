#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
struct prenotazione{
char cognome[20];
char nome[20];
char cod_fisc[20];
int n_pren;
};


item newItem(char *cognome,char *nome,char *cod_fisc,int n_pren){

	struct prenotazione *p = malloc(sizeof(struct prenotazione));

	strcpy(p->cognome,cognome);
	strcpy(p->nome,nome);
	strcpy(p->cod_fisc,cod_fisc);
	p->n_pren=n_pren;
	return p;
}
int eq(item x, item y){

	if(getNumPren(x)==getNumPren(y))
		return 0;
	else
		return -1;
}
int getNumPren(item x){
	int num = x->n_pren;
	return num;
}
void setNumPren(item x, int num){
	 x->n_pren=num;
}
item input_item(){
	struct prenotazione *x = malloc(sizeof(struct prenotazione));
	printf("Cognome:\n");
	scanf("%s",x->cognome);
	printf("Nome:\n");
	scanf("%s",x->nome);
	printf("Cod.Fisc:\n");
	scanf("%s",x->cod_fisc);

	return x;
}
void output_item(item x){
	printf("Cognome: %s\n", x->cognome);
	printf("Nome: %s\n", x->nome);
	printf("Cod.Fisc: %s\n", x->cod_fisc);
	printf("numero prenotazione: %d\n", x->n_pren);
}