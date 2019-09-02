#include "storico.h"

typedef struct prodotto *item;
#define NULLITEM NULL

item newItem(int id,char descr[20],int prezzo,int offerta,int scad);
int eq(item x, item y);
int getCod(item x);
int getScad(item x);
int getOfferta(item x);
int setOfferta(item x, int off);
item input_item();
void output_item(item x);
storico getStorico(item x);