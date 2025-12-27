#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    Salam();
    int a = 0, aP = 0, aS = 0, 
        aN = 0, tfKey = 0;
    atr comp[65];

    mReadFile(&a, &aP, comp);

    readFile(&a, &aS, &tfKey, comp, "SkillTable.txt");
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt");

    readFile(&a, &aN, &tfKey, comp, "NoteTable.txt");
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt");

    char pita[513];

    MENU();
    LIST();

    refresh();
    printf("DBMS [Arya]>> ");

    scanf("%512[^\n]s", pita);

    STARTWORD(pita);
    
    printf("\n");
    if((strcmp(GETWORD(), "INSERT") == 0 )|| (strcmp(GETWORD(), "1") == 0 )){
        INCWORD(pita);    
        if(strcmp(GETWORD(), "TabelPrimary.txt") == 0){
            atr new;

            for(int i = 0; i < 5; i++) {
                INCWORD(pita);
                switch (i){
                    case 0:{
                        strcpy(new.fkey, GETWORD());
                        break;
                    }case 1:{
                        strcpy(new.cont, GETWORD());
                        break;
                    }case 2:{
                        strcpy(new.kskill, GETWORD());
                        break;
                    }case 3:{
                        strcpy(new.knote, GETWORD());
                        break;
                    }case 4:{
                        strcpy(new.score, GETWORD());
                        break;
                    }
                }
            }

            INSm(aP, comp, new);
        }else if(strcmp(GETWORD(), "SkillTable.txt") == 0){
            atr new;

            for(int i = 0; i < 2; i++) {
                INCWORD(pita);
                switch (i){
                    case 0:{
                        strcpy(new.skey, GETWORD());
                        break;
                    }case 1:{
                        strcpy(new.sname, GETWORD());
                        break;
                    }
                }
            }
            
            INS(aS, comp, new, "SkillTable.txt");
        }else if(strcmp(GETWORD(), "NoteTable.txt") == 0){
            atr new;

            for(int i = 0; i < 2; i++) {
                INCWORD(pita);
                switch (i){
                    case 0:{
                        strcpy(new.skey, GETWORD());
                        break;
                    }case 1:{
                        strcpy(new.sname, GETWORD());
                        break;
                    }
                }
            }
            
            INS(aN, comp, new, "NoteTable.txt");
        }else if(strcmp(GETWORD(), "TableComplete.txt") == 0){
            printf("ini file join tidak bisa di otak-atik\n");
        }else{
            printf("File tidak ditemukan!\n");
        }
    }else if((strcmp(GETWORD(), "UPDATE") == 0) || (strcmp(GETWORD(), "2") == 0)){
        INCWORD(pita);
        if(strcmp(GETWORD(), "TabelPrimary.txt") == 0){
            atr new;
            
            for(int i = 0; i < 5; i++) {
                INCWORD(pita);
                switch (i){
                    case 0:{
                        strcpy(new.fkey, GETWORD());
                        break;
                    }case 1:{
                        strcpy(new.cont, GETWORD());
                        break;
                    }case 2:{
                        strcpy(new.kskill, GETWORD());
                        break;
                    }case 3:{
                        strcpy(new.knote, GETWORD());
                        break;
                    }case 4:{
                        strcpy(new.score, GETWORD());
                        break;
                    }
                }
            }
            
            UPDm(aP, comp, new);
        }else if(strcmp(GETWORD(), "SkillTable.txt") == 0){
            atr new;

            for(int i = 0; i < 2; i++) {
                INCWORD(pita);
                switch (i){
                    case 0:{
                        strcpy(new.skey, GETWORD());
                        break;
                    }case 1:{
                        strcpy(new.sname, GETWORD());
                        break;
                    }
                }
            }

            UPD(aS, comp, new, "Race.txt");
        }else if(strcmp(GETWORD(), "NoteTable.txt") == 0){
            atr new;

            for(int i = 0; i < 2; i++) {
                INCWORD(pita);
                switch (i){
                    case 0:{
                        strcpy(new.skey, GETWORD());
                        break;
                    }case 1:{
                        strcpy(new.sname, GETWORD());
                        break;
                    }
                }
            }
            
            UPD(aN, comp, new, "NoteTable.txt");
        }else if(strcmp(GETWORD(), "TableComplete.txt") == 0){
            printf("ini file join tidak bisa di otak-atik\n");
        }else{
            printf("File tidak ditemukan!\n");
        }
    }else if((strcmp(GETWORD(), "DELETE") == 0) || (strcmp(GETWORD(), "3") == 0)){
        INCWORD(pita);
        DELf(aP, aS, aN, comp);
    }else if((strcmp(GETWORD(), "SELECT") == 0) || (strcmp(GETWORD(), "4") == 0)){
        INCWORD(pita);
        SELf(aP, aS, aN, comp);
    }else{
        printf("Perintah tidak dikenali!\n");
    }

return 0;
}