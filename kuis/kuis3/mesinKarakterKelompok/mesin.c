#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Kuis 3 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void START(char pita[]){ // mulai
    indeks = 0;
    cc = pita[indeks];
}

void INC(char pita[]){ // membaca spasi ikut
    indeks++;
    cc = pita[indeks];
}

int EOP(){ // bagian pembuat berhenti
    if(cc == '='){
        return 1;
    }else{
        return 0;
    }
}

void ADV(char pita[]){ // membaca spasi tidak ikut
    indeks++;
    while ((cc == ' ') && (EOP() == 0)){
        indeks++;
        cc = pita[indeks];
    }
    // printf("0");
    cc = pita[indeks];
}

char GETCC(){ // mengembalikan nilai
    return cc;
}

int GETINDEX(){ // mengembalikan index
    return indeks;
}

int longP(int d){ // mengembalikan kelompok
    return ((indeks / d) + 1);
}