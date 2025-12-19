#include "head.h"

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

int nextBlank(char pita[]){
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
    if(pita[indeksCW] == '.'){
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

int GETSUMASCII(){
    int hasil = 0;
    for(int i = 0; i < panjangKata; i++) {
        hasil += cw[i]; 
    }
}