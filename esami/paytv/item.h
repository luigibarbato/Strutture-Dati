#include <stdbool.h>
#define NULLITEM NULL

typedef struct programma *item;

item newItem(int cod, char *titolo,char *genere,int n_giorni,bool scaricato);
int eq(item x, item y);
item input_item();
void output_item(item x);
int getCod(item x);
bool isDisponibile(item x);
bool isScaricato(item x);
int decrementaGiorno(item x);
void setScaricato(item x,bool value);