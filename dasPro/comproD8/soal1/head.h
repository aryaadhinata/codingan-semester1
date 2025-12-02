#include<stdio.h>
#include<string.h>

typedef struct {
    char kode[5];
    char judul[51];
    int waktu;
    char gen[51];
    char std[51];
} film;

typedef struct {
    char code[5];
    char jenis[51];
} option;

void read(int *n, film data[], char nama[]);
void readOption(int *n, option data[], char nama[]);
void join(film a[], option c[], option d[]);