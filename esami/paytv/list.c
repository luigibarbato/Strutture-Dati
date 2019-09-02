#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"


struct c_list {
     struct node *first;
     int size;
};

struct node {
     item value;
     struct node *next;
};


list newList(void) 
{
  struct c_list *l;
  l = malloc (sizeof(struct c_list));
  if (l != NULL) {
    l->first = NULL;
  	l->size = 0;
  }
  return l;   
// il programma client dovrà controllare che il risultato non sia NULL  
}

int emptyList(list l)
{
  if(l == NULL)
    return -1;
  return (l->size == 0);
} 


static struct node* makeNode(item val, struct node* n)
{
      struct node *nuovo = malloc (sizeof(struct node));
      
      if (nuovo != NULL) {
     	    nuovo->value = val;
        	nuovo->next = n;
	    }

      return nuovo;
}


int sizeList (list l)
{
  if(l == NULL)
    return -1;
  return l->size;
}


int posItem (list l, item val)
{
  if(l == NULL)
    return -1;
  int pos = 0;
  int found = 0;
  struct node *temp = l->first;

  while (temp!=NULL && !found)
      {
          if (eq(temp->value, val))
              found = 1;
          else {
              temp=temp->next;
              pos++;
              }
      }
  if(!found)
      	 pos = -1;
  return pos;
}


item getItem (list l, int pos)
{
  if(l == NULL)
    return NULLITEM;
  
  if (pos<0 || pos>=l->size)
        return NULLITEM;
        
  struct node *temp = l->first;
  int i =0;

  while (i < pos){
      i++;
      temp=temp->next;
  }
  
  return temp->value;
}


list reverseList1(list l) {
  if(l == NULL)
     return NULL;
  list l1 = newList();             // creiamo la nuova lista di output
  
  struct node *temp = l->first;    // serve a scorrere la lista di input

  // si scorre la lista di input e si inseriscono in testa alla nuova lista
  while(temp!=NULL) {
     l1->first = makeNode(temp->value, l1->first);
     temp=temp->next;
  }
    
  // l1->first è NULL se l è vuota o se makeNode non ha allocato memoria
  if (l1->first!=NULL) 
	     l1->size=l->size;
  // se l1->first è NULL allora l1->size è 0 (quella inizializzata da newList)
  return l1;
}


int reverseList2(list l) {
  if(l == NULL)
      return 0;
  struct node *n = l->first;       //  serve a scorrere la lista 
  struct node *prec = NULL;   //  puntatore e predecessore di n
  struct node *succ;                //  usato per salvare il successore di n

     // si scorre la lista di input e n->next viene posto uguale a prec
  while(n!=NULL) {
     succ = n->next;  // salviamo il puntatore al successivo
     n->next = prec;   // il successore di n diventa il suo predecessore
     prec = n;              // avanziamo prec sulla lista
     n = succ;             // avanziamo n sulla lista
     } 

/*  all’uscita del ciclo prec punta all’ultimo nodo della lista di input 
    che ora diventa il primo nodo della reversed list                             */
     
   l->first = prec;  

   return 1;      
}


list cloneList (list l) {
  if(l == NULL)
     return NULL;

  if(emptyList(l))
     return newList();

  struct node *temp = l->first;  // serve a scorrere la lista di input

  list l1 = newList();           // creiamo la nuova lista di output
  l1->first = makeNode(temp->value, NULL);  // creazione primo nodo
 
  struct node *temp1 = l1->first; // puntatore all’ultimo nodo di l1
    
  while(temp->next != NULL) {    // si scorre la lista di input
         temp1->next = makeNode(temp->next->value, NULL);
         temp=temp->next;
         temp1 = temp1->next;
  }

  l1->size = l->size;
  return l1;
}


int outputList (list l)
{
  if(l == NULL)
     return 0;
  int i =0;
  item val; 
  printf("Numero elementi: %d\n",l->size);
  struct node* n=l->first;
  while(n!=NULL) {
          val = n->value;
          printf("Elemento di posizione %d: ", i);  
          output_item(val);  
          printf("\n");
          n = n->next;
          i++;
  } 
  return 1;
}


list inputList (int n)
{
     if(n <= 0)
        return newList();

     item val; 
     list l = newList(); 
     
     printf("Elemento di posizione 0: ");  
     input_item(&val);  
     l->first = makeNode(val, NULL); // inserimento primo elemento 

     struct node *temp = l->first;       // puntatore all’ultimo nodo di l      

     for(int i = 1; i < n; i++) {
        printf("Elemento di posizione %d: ", i);  
        input_item(&val);  
        temp->next = makeNode(val, NULL);
        temp = temp->next;
      }  

     l->size = n;
     return l;
}    




static struct node* insertNode(struct node* n, int pos, item val)
{
     
	  if(pos == 0)          // inserimento in posizione 0
        return makeNode(val, n);

	  int i = 0;
	  struct node* prec = n;         
    while (i < pos-1) {   
        prec = prec->next;
        i++;
    }
    
    struct node* n1 = makeNode(val, prec->next);
    if(n1 == NULL) 
        return NULL;

    prec->next = n1;
    return n;  
}


static struct node* removeNode(struct node* n, int pos)
{     
    struct node* n1;    // puntatore al nodo da eliminare

    if(pos == 0) {       // eliminazione in posizione 0
        n1 = n;
        n = n->next;
        free(n1);
    }
    else {
        int i = 0;
        struct node* prec = n;         
        while (i < pos-1) {   
            prec = prec->next;
            i++;
        }
        n1 = prec->next;
        prec->next = n1->next;
        free(n1); 
      }

	  return n; 
}

int insertList (list l, int pos, item val)
{
  if(l == NULL)
     return 0;
  if (pos<0 || pos>l->size) 
     return 0;
    
  struct node* tmp= insertNode(l->first, pos, val);
  if(tmp==NULL) 
     return 0;
    
  l->first = tmp;
  l->size++;
  return 1;                            
}


int removeList (list l, int pos)
{   
  if(l == NULL)
     return 0;
    
  if (pos<0 || pos>=l->size)
     return 0; 
      
  l->first = removeNode(l->first,pos);
  l->size--;
  return 1;
}
  
int deleteList (list l) {
    if(l == NULL)
       return 0;
    
    struct node *temp = l->first;    // serve a scorrere la lista di input
    struct node *temp1;                 // punta al nodo da eliminare

    while(temp!=NULL) {   // scorre la lista per eliminare i nodi            
       temp1 = temp;
       temp=temp->next;
       free(temp1);
       }
  	
    l->first = NULL;
    l->size = 0;
    return 1;
  }
