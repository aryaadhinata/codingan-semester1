#include <stdio.h>
#include <string.h>

typedef struct{
    char fkey[5], name[17], race[17], univrs[17], team[17],
        skey[5], sname[17], krace[5], kunivrs[5], kteam[5];
    int plevel;
}atr;

void mReadFile(int *a, int *aN, atr sc[], char fileName[]);
void readFile(int *a, atr sc[], char fileName[]);

void mMerge(int *aN, atr sc[], char fileName[]);
void mFunc();