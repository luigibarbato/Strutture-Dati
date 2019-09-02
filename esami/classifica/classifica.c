#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classifica.h"
#include "ordered_set.h"
#include "list.h"

struct classifica{
	list squadre;
};
classifica newClassifica(){
	struct classifica *c = malloc(sizeof(struct classifica));
	c->squadre=newList();
	return c;
}
int aggiungiSquadra(classifica c, item i){

	return insertList(c->squadre,sizeList(c->squadre),i);
}
void stampaClassifica(classifica c){
	set ord_squadre = newSet();

	int n = sizeList(c->squadre);
	for (int i = 0; i < n; ++i)
	{
		item x = getItem(c->squadre,i);
		insertSet(ord_squadre,x);
	}

	outputSet(ord_squadre);
}
void cercaSquadra(classifica c, char *nome){

	int n = sizeList(c->squadre);
	for (int i = 0; i < n; ++i)
	{
		item x = getItem(c->squadre,i);
		if(strcmp(getNome(x),nome)==0){
			output_item(x);
			return;
		}
	}

	printf("Nessuna corrispodenza\n");
}