#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pebaikan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main() {
    char strk[100]; // untuk menyimpan string input
    int thick; // untuk menyimpan ketebalan pola

    scanf(" %s", strk);
    scanf("%d", &thick);


    if(strcmp(strk, "string") == 0){ // membandingkan string input dengan "string"
        str(thick);
    }else if(strcmp(strk, "conio") == 0){ // membandingkan string input dengan "conio"
        con(thick);
    }else if(strcmp(strk, "stdio") == 0){ // membandingkan string input dengan "stdio"
        stio(thick);
    }else if(strcmp(strk, "math") == 0){ // membandingkan string input dengan "math"
        mth(thick);
    }else if(strcmp(strk, "stdlib") == 0){ // membandingkan string input dengan "stdlib"
        std(thick);
    }else if(strcmp(strk, "ctype") == 0){ // membandingkan string input dengan "ctype"
        cty(thick);
    }else if(strcmp(strk, "malloc") == 0){ // membandingkan string input dengan "malloc"
        mllc(thick);
    }else if(strcmp(strk, "time") == 0){  // membandingkan string input dengan "time"
        tme(thick);
    }else{ // untuk input selain yang diatas
        no(thick);
    }

    return 0;
}