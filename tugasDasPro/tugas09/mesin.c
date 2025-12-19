#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 9 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int indeksCC;
int indeksCW;
int panjangKata;
char cc;
char cw[129];


void START(char pita[]){
    indeksCC = 0;
    cc = pita[indeksCC];
}

void INC(char pita[]){
    indeksCC++;
    cc = pita[indeksCC];
}

int nextBlank(char pita[]){ // cek apakah huruf didepannya huruf kecil atau bukan jika sekarang kapital
    int hasil = 0;
    if((cc >= 'A') && (cc <= 'Z')){
        indeksCC++;
        cc = pita[indeksCC];
        if((cc >= 'a') && (cc <= 'z')){
            hasil = 1; 
        }
        indeksCC--;
        cc = pita[indeksCC];
    }
    return hasil;
}

int EOP(){
    if(cc == '.'){
        return 1;
    }else{
        return 0;
    }
}

void ADV(char pita[]){
    indeksCC++;
    while ((cc == ' ') && (EOP() == 0)){
        indeksCC++;
    }
    cc = pita[indeksCC];
}

char GETCC(){
    return cc;
}

int GETIDX(){
    return indeksCC;
}

void STARTWORD(char pita[]){
    indeksCW = 0;
    panjangKata = 0;
    while(pita[indeksCW] == ' '){
        indeksCW++;
    }

    while((pita[indeksCW] != ' ') && (pita[indeksCW] != '.')){
        cw[panjangKata] = pita[indeksCW];
        indeksCW++;
        panjangKata++;
    }
    
    cw[panjangKata] = '\0';
}

void RESETWORD(){
    panjangKata = 0;
    cw[panjangKata] = '\0';
}

int EOPWORD(char pita[]){
    if((pita[indeksCW] == '.') && (panjangKata == 0)){
        return 1;
    }else{
        return 0;
    }
}

void INCWORD(char pita[]){
    panjangKata = 0;
    while(pita[indeksCW] == ' '){
        indeksCW++;
    }
    
    while((pita[indeksCW] != ' ') && (pita[indeksCW] != '.')){
        cw[panjangKata] = pita[indeksCW];
        indeksCW++;
        panjangKata++;
    }
    
    cw[panjangKata] = '\0';
}

char* GETWORD(){
    return cw;
}

int GETPANJANGKATA(){
    return panjangKata;
}

int GETSUMASCII(){ // mengeluarkan nilai ascii
    int hasil = 0;
    for(int i = 0; i < panjangKata; i++) {
        hasil += cw[i]; 
    }

    return hasil;
}

void selectionSort(char arr[][128], int n) {
    int i, j, minIndex;
    char temp[128];

    for (i = 0; i < n - 1; i++) {
        minIndex = i; // nilai indeks awal yang dicompare

        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) { // cek ururan secara alphabet
                minIndex = j;
            }
        }

        // Tukar string
        if (minIndex != i) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);
        }
    }
}