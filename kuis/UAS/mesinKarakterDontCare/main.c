#include <stdio.h>
#include "head.h"
/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 8 dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    char pita[301], next[4];
    int flags = 0, idxn[4];
    scanf("%300[^\n]s", &pita);

    START(pita);
    
    while((EOP() == 0) && (flags == 0)){
        next[0] = GETCC();
        idxn[0] = GETIDX();
        // printf("%c -- %d\n", next[0], idxn[0]);
        ADV(pita);
        if(EOP() == 0){
            next[1] = GETCC();
            idxn[1] = GETIDX();
            // printf("%c -- %d\n", next[1], idxn[1]);
            ADV(pita);
            if(EOP() == 0){
                next[2] = GETCC();
                idxn[2] = GETIDX();
                // printf("%c -- %d\n", next[2], idxn[2]);
                ADV(pita);
                if(EOP() == 0){
                    next[3] = GETCC();
                    idxn[3] = GETIDX();
                    // printf("%c -- %d\n", next[3], idxn[3]);
                }
            }
        }
        flags = 1;
    }
    // printf("===\n");
    int count = 0;
    while((EOP() == 0) && (flags == 1)){
        // for(int i = 0; i < 4; i++) {
        //     printf("%c -- %d\n", next[i], idxn[i]);
        // }
        // printf("===\n");
        if((next[0] == 'a' || next[0] == 'i' || next[0] == 'u' || next[0] == 'e' || next[0] == 'o') &&
        (next[1] == 'a' || next[1] == 'i' || next[1] == 'u' || next[1] == 'e' || next[1] == 'o') &&
        (next[3] == 'a' || next[3] == 'i' || next[3] == 'u' || next[3] == 'e' || next[3] == 'o')){
            // printf("masuk\n");
            if(count > 0){
                printf("\n");
            }
            count++;
            printf("pasangan - %d\n", count);
            for(int i = 0; i < 4; i++) {
                if(i == 2){
                    printf("%c - dont care - %d\n", next[i], idxn[i]);
                }else{
                    printf("%c - vokal - %d\n", next[i], idxn[i]);
                }
            }
            // ADV(pita);
            // ADV(pita);
            // ADV(pita);
            // ADV(pita);
            int a = 0; 
            // printf("++ %c -- %d\n", GETCC(), GETIDX());
            for(int i = 0; i < 5; i++) {
                while((EOP() == 0) && (a < 3)){
                    next[a] = next[a + 1];
                    idxn[a] = idxn[a + 1];
                    a++;
                }
                ADV(pita);
                if(EOP() == 0){
                    next[3] = GETCC();
                    idxn[3] = GETIDX();
                }
            }
        }
        int a = 0; 
        // printf("++ %c -- %d\n", GETCC(), GETIDX());
        while((EOP() == 0) && (a < 3)){
            next[a] = next[a + 1];
            idxn[a] = idxn[a + 1];
            a++;
        }
        ADV(pita);
        if(EOP() == 0){
            next[3] = GETCC();
            idxn[3] = GETIDX();
        }
    }

    if(count == 0){
        printf("tidak ada\n");
    }
    return 0;
}