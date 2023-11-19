#include <stdio.h>
#include <stdlib.h>

#include "batches.h"
#define BATCH_SIZE 3

Batch buildBatch(int size, FILE* fp)
{
    Batch batch;
    batch.data.cols = 15;
    batch.data.rows = size;
    batch.data.matrix = buildMatrix(batch.data.rows, batch.data.cols, 1);
    batch.labels = malloc(sizeof(char) * size);

    if (fp == NULL) {
        printf("Failed to open file 1\n");
        batch.labels = NULL;
        return batch;
    }

    for (int i = 0; i < BATCH_SIZE; i++)
    {
        for (int j = 0; j<= 15; j++)
            {batch.data.matrix[i][j] = readNumber(fp);}
        batch.labels[i] = fgetc(fp);
        fgetc(fp);
    }

    return batch;
}

int readNumber(FILE *fp)
{
    char c;
    int n = 0;
    while ((c = fgetc(fp)) != ',')
    {
        n = n * 10 + (c - '0');
    }

    return n;
}

void printBatch(Batch batch)
{
    for (int i = 0; i < BATCH_SIZE; i++)
    {
        for (int j = 0; j<= 15; j++)
            printf("%2.3f ", batch.data.matrix[i][j]);
        printf("%c\n", batch.labels[i]);
    }
}

void dumpBatch(Batch batch)
{
    for (int i = 0; i < batch.data.rows; i++)
    {
        free(batch.data.matrix[i]);
    }
    free(batch.data.matrix);
    free(batch.labels);
}