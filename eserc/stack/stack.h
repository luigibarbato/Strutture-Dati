#include <stdio.h>
#include <stdlib.h>
#include <bool.h>
#include "item.h"

Stack newStack(char *nome);
bool isEmpty(Stack s);
bool push(Stack s,Item i);
bool pop(Stack s);