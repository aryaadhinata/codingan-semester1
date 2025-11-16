#include <stdio.h>
#include <string.h>

void turn(int i, char nama[], int damage, char tipe[], int *Ehp, char Etipe[]);
void Eturn(int i, char nama[], int *hp, int Edamage,  char tipe[], char Etipe[]);
void status(char nama[], int hp);
void Estatus(int Ehp, int *l);
void pertarungan(int h, int n, int l, char nama[][129], int hp[], int damage[], char tipe[][129], int Ehp, int Edamage, char Etipe[]);
void endWorld(int h, int n, int l, int Ehp, char nama[][129], char Fnama[][129], int hp[], int Fhp[], char rank[][129], char Frank[][129], int damage[], int Fdamage[]);