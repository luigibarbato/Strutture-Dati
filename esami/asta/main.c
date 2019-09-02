#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asta.h"
#include "storico.h"
int main(){
item i = newItem(0,"merda",12,1,0);
asta a = newAsta("ciao");
addProdotto(a,i);
storico s = newStorico(0);
nuovaOfferta(s, 12);
nuovaOfferta(s, 15);
printStorico(s);
int res = getUltimaOfferta(s);
printf("Ultima offerta: %d\n", res);
}