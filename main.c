#include <stdio.h>
#include <stdlib.h>
#include "batches.h"
#define BATCH_SIZE 3

int main()
{
    const char *filename = "/home/d3lle/Documenti/myBigVault/Informatica/C/NN/Dataset/letter.txt";
    FILE *fp = fopen(filename, "r");

    Batch batch = buildBatch(BATCH_SIZE, fp);
    printBatch(batch);
    dumpBatch(batch);

    fclose(fp);
    return 0;
}

