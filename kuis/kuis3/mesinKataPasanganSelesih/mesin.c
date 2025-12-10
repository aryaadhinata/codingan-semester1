#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Kuis 3 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void STARTWORD(char pita[]){
    indeks = 0;
    panjangKata = 0;
    while(pita[indeks] == ' '){
        indeks++;
    }

    while((pita[indeks] != ' ') && (pita[indeks] != '=')){
        if((pita[indeks] == 'a' || pita[indeks] == 'i' || pita[indeks] == 'u' ||
            pita[indeks] == 'e' || pita[indeks] == 'o') && (pita[indeks + 1] == 'a' ||
            pita[indeks + 1] == 'i' || pita[indeks + 1] == 'u' || pita[indeks + 1] == 'e' ||
            pita[indeks + 1] == 'o')){
            for(int i = 0; i < 4; i++){
                cw[panjangKata] = pita[indeks + i];
            }
        }
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
    
    while((pita[indeks] != ' ') && (pita[indeks] != '=')){
        if((pita[indeks] == 'a' || pita[indeks] == 'i' || pita[indeks] == 'u' ||
            pita[indeks] == 'e' || pita[indeks] == 'o') && (pita[indeks + 1] == 'a' ||
            pita[indeks + 1] == 'i' || pita[indeks + 1] == 'u' || pita[indeks + 1] == 'e' ||
            pita[indeks + 1] == 'o')){
            for(int i = 0; i < 4; i++){
                cw[panjangKata] = pita[indeks + i];
            }
        }
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
    if(pita[indeks] == '='){
        return 1;
    }else{
        return 0;
    }
}