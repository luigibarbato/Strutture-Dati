#include "item.h"
typedef struct classifica *classifica;

classifica newClassifica();
int aggiungiSquadra(classifica c, item i);
void cercaSquadra(classifica c, char *nome);
void stampaClassifica(classifica c);