#include "item.h"
typedef struct paytv *paytv;

paytv newPaytv(char *nom_propr);
int emptyPayTv(paytv p);
int addProgramma(paytv p, item i);
void visualizzaProgramma(paytv p, int cod);
int decrementaGiorni(paytv p);
void outputPayTv(paytv p);
int cancellaProgrammiScaduti(paytv p);
int addDownload(paytv p,item i);
int svuotaCodaDownload(paytv p);
void stampaScaricati(paytv p);