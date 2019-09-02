#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "ordered_set.h"

struct c_set{
	struct node *first;
	int size;
};

struct node{
	item value;
	struct node *next;
};

set newSet(){
	struct c_set *s;
	s=malloc(sizeof(struct c_set));
	if (s!=NULL){
		s->first=NULL;
		s->size=0;
	}
	return s;
}

int emptySet(set s) {
	if(s == NULL)  return -1;
	return (s->size == 0);
}


static struct node* makeNode(item val, struct node* nxt)
{
	struct node *nuovo = malloc (sizeof(struct node));
		if (nuovo != NULL) {
			nuovo->value = val;
			nuovo->next = nxt;
	}
	return nuovo;
}

int insertSet(set s, item val)
{
	if(s== NULL)
	  return -1;

	struct node *temp, *temp1;

	if(s->first == NULL) {         // caso s vuoto
	temp1 = makeNode(val, NULL);
	     if(temp1 == NULL)
			 return -1;                // inserimento non riuscito
	     s->first = temp1;
	     s->size++;
	     return 1;                         // inserimento riuscito
	}

	int res = cmpItem(s->first->value, val);

	     if(res == 0) 
		     return 0;  // elemento gia’ presente in prima posizione					 

	     if(res > 0) {  // s->first>value > val  => inserimento in testa
			temp1 = makeNode(val, s->first);
			if(temp1 == NULL) 
				 return -1;            // inserimento non riuscito
		 s->first = temp1;
			s->size++;
			return 1;                         // inserimento riuscito
		}

	     temp = s->first;      // per attraversare i nodi         
	     int found = 0;
	     int greater = 0;     
	
	while (temp->next != NULL && !found && !greater) {
		     res = cmpItem(temp->next->value, val);
		     if (res == 0)
			     found = 1;                // elemento trovato
		     else if(res > 0)               // trovato elemento maggiore
			greater = 1;
				 else temp=temp->next;    // continua ricerca
		}

		 if(found) return 0;        // elemento già presente
	 	
		 temp1 = makeNode(val, temp->next);
		 if(temp1 == NULL)
					return -1;                 // inserimento non riuscito             
		 temp->next = temp1;
		 s->size++;
		 return 1;                         // inserimento riuscito
}


int contains(set s, item val)
{
			if(s== NULL) return 0;

			int res;
			int found = 0;         
			int greater = 0;               
			struct node *temp = s->first;     // per attraversare i nodi         
																												 
			while (temp != NULL && !found && !greater) {
					res = cmpItem(temp->value, val);
					if (res == 0)
		found = 1;               // elemento trovato
					else if (res > 0)                   // temp->value > val
		greater = 1;             // non può essere trovato            
					else temp=temp->next;     // continua ricerca
			 }
			 return found; 
}


int removeSet(set s, item val)
{
	if(s== NULL)
	return -1;

	if(s->first == NULL) {         // caso s vuoto
	return 0;                         // rimozione non riuscita
	}

	struct node *temp = s->first;      // per attraversare i nodi         

	int res = cmpItem(temp->value, val); 

	if(res == 0) {      // elemento presente in prima posizione
	  s->first = s->first->next;   
	  free(temp);    
		 s->size--; 
		 return 1;           
	  } 		
	
	if(res > 0)   // s->first->value  >  val
						 return 0;   // val non può essere trovato
	// visitiamo il resto della struttura a puntatori
	// temp punta a nodo precedente quello corrente

				int found = 0;
				int greater = 0;    
	 
				while (temp->next != NULL && !found && !greater) {
						 res = cmpItem(temp->next->value, val);
						 if (res == 0)
									 found = 1;                // elemento trovato
						 else if(res > 0)               // trovato elemento maggiore
			   greater = 1;      // fermiamo la ricerca
										 else temp=temp->next;    // continua ricerca
					}
					if(!found)         // elemento non presente
					 	    return 0;  

						// se found == 1, temp punta a nodo precedente
						// a quello da rimuovere (che contiene val)

						struct node *temp1 = temp->next;   // nodo da rimuovere
						temp->next = temp1->next;
						free(temp1);
						 s->size--;
						return 1;                                      // eliminazione effettuata
					}


int outputSet(set s){
	if (s==NULL)
		return 0;
	if (s->first==NULL)
		return 0;
	struct node *temp=s->first;
	while(temp!=NULL){
		output_item(temp->value);
		printf("\t");
		temp=temp->next;
	}
	return 1;
}
