#define NULLITEM NULL
typedef struct prenotazione *item;

item newItem(char *cognome,char *nome,char *cod_fisc,int n_pren);
int eq(item x, item y);
int getNumPren(item x);
void setNumPren(item x, int num);
item input_item();
void output_item(item x);