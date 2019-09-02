#include "item.h"
typedef struct asta *asta;

asta newAsta(char *nome);
int emptyAsta(asta a);
int addProdotto(asta a, item i);
item cercaProdotto(asta a, int cod);
int offerta(asta a, int cod,int offerta);
int decrementaScadenza(asta a);
void outputProdDisp(asta a);
void outputProdVenduti(asta a);
int cancellaProdVenduti(asta a);
