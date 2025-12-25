#include <stdio.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char fkey[5], cont[65], skey[5], sname[65],
        kskill[65], knote[65],
        scont[65], sskill[65], snote[65];
    int score;
}atr;

void MENU();
void LIST();

void mReadFile(int *a, int *aP, atr sc[]);
void readFile(int *a, int *b, int *tF, atr sc[], char fileName[]);
void mMerge(int *aN, int *aR, int *aU, int *tF, atr sc[], char fileName[]);

void refresh();

void INSm(int n, atr obj[], char fileName[]);
void INS(int n, atr obj[], char fileName[]);
void INSf(int aN, int aNo, int As, atr obj[]);

void UPDm(int n, atr obj[], char fileName[]);
void UPD(int n, atr obj[], char fileName[]);
void UPDf(int aN, int aNo, int As, atr obj[]);

void DELm(int n, atr obj[], char fileName[]);
void DEL(int n, atr obj[], char fileName[]);
void DELf(int aN, int aNo, int As, atr obj[]);

int dgtlen(int n);

void SELm(int n, atr obj[], char fileName[]);
void SEL(int n, atr obj[], char fileName[]);
void SELf(int aN, int aNo, int As, atr obj[]);