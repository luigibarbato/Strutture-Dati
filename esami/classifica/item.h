#define NULLITEM NULL

typedef struct squadra *item;

item newItem(char *nome,int punteggio,int n_partite,int n_segnati,int n_subiti);
int cmpItem(item x,item y);
int eq(item x, item y);
item input_item();
void output_item(item x);
char *getNome(item x);