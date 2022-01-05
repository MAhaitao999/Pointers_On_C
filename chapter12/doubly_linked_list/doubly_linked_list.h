#include <stdio.h>
#include <stdlib.h>

typedef struct _doubleNode_ {
    struct _doubleNode_ *fwd;
    struct _doubleNode_ *bwd;
    int value;
} doubleNode;

int dll_insert1(doubleNode *rootp, int value);
int dll_insert2(doubleNode *rootp, int value);
int dll_insert3(doubleNode *rootp, int value);
int dll_insert4(doubleNode *rootp, int value);
int dll_insert5(doubleNode *rootp, int value);

