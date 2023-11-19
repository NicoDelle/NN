#include <stdio.h>
#include "matrices.h"

typedef struct
{
    Matrix data;
    char *labels;
} Batch;

Batch buildBatch(int size, FILE* fp);
int readNumber(FILE *fp);
void printBatch(Batch batch);
void dumpBatch(Batch batch);
