#define maxstack 100
typedef struct strStack
{
char nome[10];
int size;
item data[maxstack];	
}*Stack;

Stack newStack(char *nome){

Stack tmp = malloc(sizeof(struct strStack));
tmp->size = 0;
strcpy(tmp->nome,nome);

return tmp;
}

bool isEmpty(Stack s){

	if(s->size == 0) 
		return true;
	else
		return false;
}

bool push(Stack s,Item i){

	if(s->size == maxstack) return false;

	s->data[s->size] = i;
	(s->size)++;
return true;
}

bool pop(Stack s){

	if(s->size <= 0) return false;
	
	free(data[s->size]);
	(s->size)--;

	return true;
}

 	