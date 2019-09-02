#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "item.h"
#include "list.h"
#include "paytv.h"
#include "queue.h"
struct paytv
{
	char nom_propr[20];
	list programmi;
	queue download;
};

item static cercaProgramma(paytv p, int cod);

paytv newPaytv(char *nom_propr){
	struct paytv *p = malloc(sizeof(struct paytv));

	strcpy(p->nom_propr,nom_propr);
	p->programmi=newList();
	p->download=newQueue();

	return p;

}
int emptyPayTv(paytv p){

	return(emptyList(p->programmi));
}

int addProgramma(paytv p, item i){
	
	item nuovo = cercaProgramma(p,getCod(i));

	if( nuovo!=NULL || !isDisponibile(i))
		return -1;

	return insertList(p->programmi,sizeList(p->programmi),i);
}
void visualizzaProgramma(paytv p,int cod){
	if(emptyPayTv(p))
		printf("Errore\n");

	item i = cercaProgramma(p,cod);

	if(i == NULLITEM)
		printf("Nessuna corrispodenza \n");
	else
		output_item(i);
}

int decrementaGiorni(paytv p){
	if(emptyPayTv(p))
		return -1;

	int n = sizeList(p->programmi);

	for(int i=0; i<n; i++){

		item tmp = getItem(p->programmi,i);
		decrementaGiorno(tmp);
	}

	return 0;
}
void outputPayTv(paytv p){
	if(emptyPayTv(p))
		printf("Errore\n");

	int n = sizeList(p->programmi);

	for(int i=0; i<n; i++){

		item tmp = getItem(p->programmi,i);
		output_item(tmp);
	}

}
int cancellaProgrammiScaduti(paytv p){
	if(emptyPayTv(p))
		return -1;

	int n = sizeList(p->programmi);

	for(int i=0; i<n; i++){

		item s = getItem(p->programmi,i);
		if(!isDisponibile(s))
			removeList(p->programmi,i);
	}
}
int addDownload(paytv p,item i){
		if(emptyPayTv(p))
			return -1;
		if(i == NULLITEM)
			return -1;

		return enqueue(p->download,i);
}
int svuotaCodaDownload(paytv p){
	if(p->download==NULLQUEUE)
		return -1;

	while(emptyQueue(p->download)!=0){
		item tmp = dequeue(p->download);
		item i = cercaProgramma(p,getCod(tmp));
		setScaricato(i,true);
	}

	return 1;
}
void stampaScaricati(paytv p){
	if(emptyPayTv(p))
		printf("Errore\n");

	int n = sizeList(p->programmi);
	for(int i=0; i<n; i++){

		item tmp = getItem(p->programmi,i);
		if(isScaricato(tmp))
			output_item(tmp);
	}

}
item static cercaProgramma(paytv p, int cod){
	int n = sizeList(p->programmi);

	for(int i=0; i<n; i++){

		item s = getItem(p->programmi,i);
		if(getCod(s) == cod)
		{
			return s;
		}
	}

	return NULLITEM;
}
