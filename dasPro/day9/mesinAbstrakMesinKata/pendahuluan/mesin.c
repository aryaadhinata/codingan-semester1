#include "head.h"

void STARTWORD(char pita[]){
    indeks = 0;
    panjangKata = 0;
    while(pita[indeks] == ' '){
        indeks++;
    }

    while((pita[indeks] != ' ') && (pita[indeks] != '.')){
        cw[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }
    
    cw[panjangKata] = '\0';
}

void RESETWORD(){
    panjangKata = 0;
    cw[panjangKata] = '\0';
}


void INCWORD(char pita[]){
    panjangKata = 0;
    while(pita[indeks] == ' '){
        indeks++;
    }
    
    while((pita[indeks] != ' ') && (pita[indeks] != '.')){
        cw[panjangKata] = pita[indeks];
        indeks++;
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

int EOPWORD(char pita[]){
    if(pita[indeks] == '.'){
        return 1;
    }else{
        return 0;
    }
}