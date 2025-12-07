#include "head.h"

void mReadFile(int *a, int *aN, atr sc[], char fileName[]){
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    int rval = fscanf(ftemp, "%s %s %s %s %s %d", sc[*a].fkey, sc[*a].name, 
            sc[*a].krace, sc[*a].kunivrs, sc[*a].kteam, &sc[*a].plevel);
    
    if((strcmp(sc[*a].fkey, "####") == 0) || rval == EOF){
        printf("File Kosong\n");
    }else{
        while(strcmp(sc[*a].fkey, "####") != 0){
            *a = *a +1;
            fscanf(ftemp, "%s %s %s %s %s %d", sc[*a].fkey, sc[*a].name, 
                    sc[*a].krace, sc[*a].kunivrs, sc[*a].kteam, &sc[*a].plevel);
        }
    }
    *aN = *a;
    fclose(ftemp);
}

void readFile(int *a, atr sc[], char fileName[]){
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    if(*a != 0){
        *a = 0;
    }

    int rval = fscanf(ftemp, "%s %s", sc[*a].skey, sc[*a].sname);
    
    if((strcmp(sc[*a].skey, "####") == 0) || rval == EOF){
        printf("File Kosong\n");
    }else{
        while(strcmp(sc[*a].skey, "####") != 0){
            *a = *a +1;
            fscanf(ftemp, "%s %s", sc[*a].skey, sc[*a].sname);
        }
    }

    fclose(ftemp);
}

void mMerge(int *aN, atr sc[], char fileName[]){
    FILE *fcFile;
    FILE *fFighter;
    FILE *fRace;
    FILE *fUnivrs;
    FILE *fTeam;

    fcFile = fopen(fileName, "w");
    fFighter = fopen("Fighter.txt", "r");
    fRace = fopen("Race.txt", "r");
    fUnivrs = fopen("Universe.txt", "r");
    fTeam = fopen("Team.txt", "r");


    fclose(fcFile);
    fclose(fFighter);
    fclose(fRace);
    fclose(fUnivrs);
    fclose(fTeam);
}

void mFunc(){
    char inp[5];

    do{
        
        printf("Jika ingin melanjutkan ketik 'yes'\n >> ");
        scanf("%s", inp);
    }while((strcmp(inp, "yes") == 0) || (strcmp(inp, "YES") == 0) ||
            (strcmp(inp, "y") == 0) || (strcmp(inp, "Y") == 0));
}