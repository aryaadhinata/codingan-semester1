#include <stdio.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char fkey[5], cont[125], skey[5], sname[125],
        kskill[125], knote[125],
        scont[125], sskill[125], snote[125],
        score[125];
}atr;

void Salam();
void MENU();
void LIST();

extern int indeks;
extern int panjangKata;
extern char cw[129];

void STARTWORD(char pita[]);
void RESETWORD();
void INCWORD(char pita[]);
void INCWORD(char pita[]);
char* GETWORD();
int GETPANJANGKATA();
int EOPWORD(char pita[]);

void mReadFile(int *a, int *aP, atr sc[]);
void readFile(int *a, int *b, int *tF, atr sc[], char fileName[]);
void mMerge(int *aN, int *aR, int *aU, int *tF, atr sc[], char fileName[]);

void refresh();

void INSm(int n, atr obj[], atr new);
void INS(int n, atr obj[], atr new, char fileName[]);

void UPDm(int n, atr obj[], atr new);
void UPD(int n, atr obj[], atr new, char fileName[]);

void DELm(int n, atr obj[]);
void DEL(int n, atr obj[], char fileName[]);
void DELf(int aN, int aNo, int As, atr obj[]);

void SELm(int n, atr obj[]);
void SEL(int n, atr obj[], char fileName[]);
void SELf(int aN, int aNo, int As, atr obj[]);