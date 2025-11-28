#include <stdio.h>
#include <string.h>


typedef struct{
    char judul[51], musisi[51];
    int tahun;
}dataName;


void writeToFileName(int n, dataName source[], char fileName[]);
void readFileName(int *n, dataName source[], char fileName[]);
