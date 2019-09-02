#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classifica.h"
int main(){

item a = newItem("Boromeo",2,4,1,2);
item b = newItem("Antonioli",2,4,1,2);
classifica c = newClassifica();
aggiungiSquadra(c,a);
aggiungiSquadra(c,b);
cercaSquadra(c,"Antonioli");
}