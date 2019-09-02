#include "gestore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	gestore g = newGestore();
	nuovaPrenotazione(g);
	nuovaPrenotazione(g);
	nuovaPrenotazione(g);
	serviCliente(g,0);
	visualizzaNumero(g,0);
	serviCliente(g,0);
	visualizzaNumero(g,0);
	sizeClientiDaServire(g);
}