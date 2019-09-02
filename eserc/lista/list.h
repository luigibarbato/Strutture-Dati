// file list.h

typedef struct c_list *list;

// prototipi

list newList(void);

int emptyList(list l);

int sizeList (list l);

int posItem (list l, item val);

item getItem (list l, int pos);

list reverseList1(list l);

int reverseList2(list l);

list cloneList (list l);

int outputList (list l);

list inputList (int n);

int insertList (list l, int pos, item val);

int removeList (list l, int pos);

int deleteList (list l);