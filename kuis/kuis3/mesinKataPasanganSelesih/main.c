#include <stdio.h>
#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Kuis 3 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    char pita[301];
    scanf("%300[^\n]s", pita);

    STARTWORD(pita);
    int count = 0;
    while (EOPWORD(pita) == 0){
        printf("%s\n", GETWORD())
        INCWORD(pita);
        if((count % 2 == 0) && (count != 0)){
            printf("\n");
            count++;
        }
    }

    printf("yang memenuhi syarat: %d pasangan", count);
    return 0;
}