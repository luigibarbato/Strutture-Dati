#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asta.h"
#include "list.h"

struct asta{
	char nome[20];
	list prodotti;
};

asta newAsta(char *nome){
	struct asta *a=malloc(sizeof(struct asta));
	strcpy(a->nome,nome);
	a->prodotti=newList();
}

int emptyAsta(asta a){
	return emptyList(a->prodotti);
}

int addProdotto(asta a, item i){
	item x = cercaProdotto(a,getCod(i));

	if(x!=NULL || getScad(i)<0)
		return -1;
	
	return insertList(a->prodotti,sizeList(a->prodotti),i);
}

item cercaProdotto(asta a, int cod){

	if(emptyAsta(a))
		return NULLITEM;

	int n = sizeList(a->prodotti);

	for (int i = 0; i < n; ++i)
	{
		item x = getItem(a->prodotti,i);
		if(getCod(x)==cod)
			return x;

	}

	return NULLITEM;
}
int offerta(asta a, int cod,int offerta){
	if(emptyAsta(a))
		return -1;

	item i = cercaProdotto(a,cod);

	if(i!=NULLITEM && getOfferta(i)<offerta)
	{
		setOfferta(i,offerta);
		return 0;
	}

	return -1;

}
int decrementaScadenza(asta a){
	if(emptyAsta(a))
		return -1;

		int n = sizeList(a->prodotti);

	for (int i = 0; i < n; ++i)
	{
		item x = getItem(a->prodotti,i);
		int decr = (getOfferta(x))-1;
		if(!setOfferta(x,decr))
			return -1;

	}

	return 0;
}
void outputProdDisp(asta a){

	if(emptyAsta(a))
		printf("Nessun prodotto disponibile\n");

	int n = sizeList(a->prodotti);

	for (int i = 0; i < n; ++i)
	{
		item x = getItem(a->prodotti,i);
		output_item(x);
	}

}
void outputProdVenduti(asta a){
	if(emptyAsta(a))
		printf("Nessun prodotto disponibile\n");

	int n = sizeList(a->prodotti);

	for (int i = 0; i < n; ++i)
	{
		item x = getItem(a->prodotti,i);
		if(getScad(x)<=0)
		output_item(x);
	}
}
int cancellaProdVenduti(asta a){
		if(emptyAsta(a))
		printf("Nessun prodotto disponibile\n");

	int n = sizeList(a->prodotti);

	for (int i = 0; i < n; ++i)
	{
		item x = getItem(a->prodotti,i);
		if(getScad(x)<=0)
			return removeList(a->prodotti,i);
	}
}
