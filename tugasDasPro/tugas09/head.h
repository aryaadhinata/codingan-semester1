#include <stdio.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 9 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

extern int indeksCC;
extern int indeksCW;
extern int panjangKata;
extern char cc;
extern char cw[129];

void START(char pita[]);
void INC(char pita[]);
int nextBlank(char pita[]);
int EOP();
void ADV(char pita[]);
char GETCC();
int GETIDX();

void STARTWORD(char pita[]);
void RESETWORD();
void INCWORD(char pita[]);
char* GETWORD();
int GETPANJANGKATA();
int EOPWORD(char pita[]);
int GETSUMASCII();
void selectionSort(char arr[][128], int n);