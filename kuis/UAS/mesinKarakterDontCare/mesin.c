#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 8 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void START(char pita[]){
    indeks = 0;
    cc = pita[indeks];
}

void INC(char pita[]){
    indeks++;
    cc = pita[indeks];
}

int EOP(){
    if(cc == '*'){
        return 1;
    }else{
        return 0;
    }
}

void ADV(char pita[]){
    indeks++;
    cc = pita[indeks];
    while ((cc == ' ') && (EOP() == 0)){
        indeks++;
        cc = pita[indeks];
    }
}

char GETCC(){
    return cc;
}

int GETIDX(){
    return indeks;
}