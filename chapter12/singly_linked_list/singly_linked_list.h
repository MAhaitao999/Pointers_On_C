#include <stdio.h>
#include <stdlib.h>

typedef struct _singleNode_ {
    struct _singleNode_ *link;
    int value;
} singleNode;

int sll_insert1(singleNode *current, int new_value);

int sll_insert2(singleNode **rootp, int new_value);

int sll_insert3(register singleNode **linkp, int new_value);