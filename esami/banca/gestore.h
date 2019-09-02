#include "item.h"

typedef struct gestore *gestore;

gestore newGestore();
int nuovaPrenotazione(gestore g);
int serviCliente(gestore g, int sportello);
int visualizzaNumero(gestore g, int sportello);
int sizeClientiDaServire(gestore g);
