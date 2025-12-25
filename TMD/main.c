#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    int a = 0, aP = 0, aS = 0, 
        aN = 0, tfKey = 0;
    atr comp[65];

    mReadFile(&a, &aP, comp);

    readFile(&a, &aS, &tfKey, comp, "SkillTable.txt");
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt");

    readFile(&a, &aN, &tfKey, comp, "NoteTable.txt");
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt");

    char inp[129];

    MENU();
    do{
        printf("Jika ingin berhentik ketik 'Yes'\n");
        printf("Untuk meihat menu tekan 0. MENU\n");
        printf(">> ");
        scanf(" %s", inp);
        printf("\n");
        refresh();
        if((strcmp(inp, "INSERT") == 0 )|| (strcmp(inp, "1") == 0 )){
            INSf(aP, aS, aN, comp);
        }else if((strcmp(inp, "UPDATE") == 0) || (strcmp(inp, "2") == 0)){
            UPDf(aP, aS, aN, comp);
        }else if((strcmp(inp, "DELETE") == 0) || (strcmp(inp, "3") == 0)){
            DELf(aP, aS, aN, comp);
        }else if((strcmp(inp, "SELECT") == 0) || (strcmp(inp, "4") == 0)){
            SELf(aP, aS, aN, comp);
        }else if((strcmp(inp, "MENU") == 0) || (strcmp(inp, "0") == 0)){
            MENU();
        }else if((strcmp(inp, "yes") != 0) && (strcmp(inp, "Yes") != 0) &&
            (strcmp(inp, "y") != 0) && (strcmp(inp, "Y") != 0)){
            printf("Input tidak sesuai!\n");
        }

    }while((strcmp(inp, "yes") != 0) && (strcmp(inp, "Yes") != 0) &&
            (strcmp(inp, "y") != 0) && (strcmp(inp, "Y") != 0));
    return 0;
}