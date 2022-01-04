#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *fwd;
    struct NODE *bwd;
    int         value;
} Node;

