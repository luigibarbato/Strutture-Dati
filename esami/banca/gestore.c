#include "queue.h"
#include "gestore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSPORTELLI 2

struct gestore{
	queue prenotazioni;
	int last;
	int sportelli[2];
};

gestore newGestore(){
	struct gestore *g = malloc(sizeof(struct gestore));

	g->prenotazioni=newQueue();
	g->last=0;
	g->sportelli[0]=0;
	g->sportelli[1]=0;

	return g;
}
int nuovaPrenotazione(gestore g){

	if(g==NULL)
		return -1;
	item x = input_item(&x);
	if(x==NULLITEM)
		return -1;

	setNumPren(x,g->last+1);
	(g->last)++;

	return enqueue(g->prenotazioni,x);
}
int serviCliente(gestore g, int sportello){

	if(g==NULL)
		return -1;

	if(sportello < 0 || sportello > MAXSPORTELLI)
		return -1;

	item i = dequeue(g->prenotazioni);
	output_item(i);
	g->sportelli[sportello]=getNumPren(i);
	return 0;
}
int visualizzaNumero(gestore g, int sportello){
	if(g==NULL)
		return -1;

	if(sportello < 0 || sportello > MAXSPORTELLI)
		return -1;


	int servito = g->sportelli[sportello];
	printf("Numero servito: %d\n",servito);

	return 0;
}
int sizeClientiDaServire(gestore g){
	if(g==NULL)
		return -1;
	int size = sizeQueue(g->prenotazioni);
	printf("N. di clienti da servire: %dan",size);
}