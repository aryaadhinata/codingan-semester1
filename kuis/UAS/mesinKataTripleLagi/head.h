#include <stdio.h>
#include <string.h>


int idx; // index
int wlen; // panjang current word
char cw[51]; // current word

int eop(char pita[]);
void start(char pita[]);
void reset();
void inc(char pita[]);
int countKata(char pita[]);
char* getcw();
int getlen();