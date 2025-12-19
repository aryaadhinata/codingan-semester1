#include <stdio.h>
#include <string.h>

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