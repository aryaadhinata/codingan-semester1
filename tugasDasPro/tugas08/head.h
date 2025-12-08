#include <stdio.h>
#include <string.h>

typedef struct{
    char fkey[5], name[33], race[33], univrs[33], team[33],
        skey[5], sname[33], krace[5], kunivrs[5], kteam[5];
    int plevel;
}atr;

void mReadFile(int *a, int *aN, atr sc[], char fileName[]);
void readFile(int *a, int *b, atr sc[], char fileName[]);

void mMerge(int *aN, int *aR, int *aU, int *aT, atr sc[], char fileName[]);
void mFunc();