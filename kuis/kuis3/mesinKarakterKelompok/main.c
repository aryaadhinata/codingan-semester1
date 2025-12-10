#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Kuis 3 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    char pita[301];
    char kar;
    int ang;
    scanf("%300[^\n]s", pita); 
    scanf(" %c", &kar);
    scanf("%d", &ang);

    START(pita);

    while (EOP() == 0) { // kondisi loop "EOP tidak berfungsi"
        if (GETCC() == kar ){
            printf("%c -- %d -- %d", GETCC(), GETINDEX(), longP(ang));
            printf("\n");
        }
        INC(pita);
    }

    return 0;
}