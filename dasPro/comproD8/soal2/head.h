#include <stdio.h>
#include <string.h>

typedef struct{
    char judul[51];
    char kode[51];
    char genre[51];
    char studio[51];
    int menit;
}dataName;

void readFileName(int *n, dataName source[], char fileName[]); // prosedur untuk membaca file
void writeToFileName(int n, dataName source[], char fileName[]); // prosedur untuk menulis file