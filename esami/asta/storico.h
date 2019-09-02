typedef struct storico *storico;

storico newStorico(int cod);
int nuovaOfferta(storico s, int offerta);
int emptyStorico(storico s);
int getUltimaOfferta(storico s);
void visualizzaOfferte(storico s);
int cancellaOfferte(storico s);
void printStorico(storico s);