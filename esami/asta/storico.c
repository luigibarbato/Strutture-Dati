#include "storico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodo{
	int valore;
	struct nodo *next;
};

struct storico{
int cod;
struct nodo *top;
};

storico newStorico(int cod){
	struct storico *s = malloc(sizeof(struct storico));
	s->cod=cod;
	s->top=NULL;

	return s;
}
int emptyStorico(storico s){
	if(s->top==NULL)
		return -1;
	else
		return 0;
}
int getUltimaOfferta(storico s){
	if(emptyStorico(s))
		return -1;
	else
		return s->top->valore;
}
void visualizzaOfferte(storico s){
	if(emptyStorico(s))
		printf("Errore!\n");


printf("Storico delle offerte per il prodotto %d", s->cod);
	int i=0;
	while(!emptyStorico(s)){

		struct nodo *tmp = malloc(sizeof(struct nodo));
			tmp=s->top;
			int valore = s->top->valore;
			printf("Offerta n.%d dal valore di: %d",i,valore);
			s->top=s->top->next;
			free(tmp);
			i++;
	}

}
int cancellaOfferte(storico s){
		if(emptyStorico(s))
		return -1;

	while(!emptyStorico(s)){

		struct nodo *tmp = malloc(sizeof(struct nodo));
			tmp=s->top;
			s->top=s->top->next;
			free(tmp);
	}

	return 0;
}

int nuovaOfferta(storico s, int offerta){

	if(getUltimaOfferta(s)>offerta)
		return -1;

	struct nodo *tmp = malloc(sizeof(struct nodo));
	tmp->valore=offerta;
	tmp->next=s->top;
	s->top=tmp;
	return 0;
}

void printStorico(storico s){

	storico b = newStorico(s->cod);

	int i=0;
	while(!emptyStorico(s)){

		struct nodo *newNodo = malloc(sizeof(struct nodo));
		struct nodo *tmp = malloc(sizeof(struct nodo));
		tmp=s->top;
		newNodo->valore=s->top->valore;
		newNodo->next=b->top;
		b->top=newNodo;
		int valore = s->top->valore;
		printf("Offerta n.%d dal valore di: %d\n",i,valore);
		s->top=s->top->next;
		free(tmp);
		i++;
	}
	while(!emptyStorico(b)){

		struct nodo *newNodo = malloc(sizeof(struct nodo));
		struct nodo *tmp = malloc(sizeof(struct nodo));
		tmp=b->top;
		newNodo->valore=b->top->valore;
		newNodo->next=s->top;
		s->top=newNodo;
		int valore = b->top->valore;
		b->top=b->top->next;
		free(tmp);
		i++;
	}

}