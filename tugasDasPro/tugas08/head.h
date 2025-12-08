#include <stdio.h>
#include <string.h>

typedef struct{
    char fkey[5], name[65], race[65], univrs[65], team[65],
        skey[5], sname[65], krace[5], kunivrs[5], kteam[5],
        srace[65], sunivrs[65], steam[65];
    int plevel;
}atr;

void mReadFile(int *a, int *aN, atr sc[], char fileName[]);
void readFile(int *a, int *b, int *tF, atr sc[], char fileName[]);
void mMerge(int *aN, int *aR, int *aU, int *aT, int *tF, atr sc[], char fileName[]);

void refresh();

void INSm(int n, atr obj[], char fileName[]);
void INS(int n, atr obj[], char fileName[]);
void INSf(int aN, int aR, int aU, int aT, atr obj[]);

void UPDf(int aN, int aR, int aU, int aT, atr obj[]);