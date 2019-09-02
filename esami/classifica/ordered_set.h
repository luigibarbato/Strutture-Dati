typedef struct c_set *set;

set newSet(void);
int emptySet(set s);
int insertSet(set s, item e);
int contains(set s, item val);
int removeSet(set s, item val);
int outputSet(set s);
