#include "head.h"

void mReadFile(int *a, int *aN, atr sc[], char fileName[]){
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    int rval = fscanf(ftemp, "%s %s %s %s %s %d\n", sc[*a].fkey, sc[*a].name, 
                    sc[*a].krace, sc[*a].kunivrs, sc[*a].kteam, &sc[*a].plevel);
    
    if((strcmp(sc[*a].fkey, "####") == 0) || rval == EOF){
        printf("File Kosong\n");
    }else{
        while(strcmp(sc[*a].fkey, "####") != 0){
            *a = *a +1;
            fscanf(ftemp, "%s %s %s %s %s %d\n", sc[*a].fkey, sc[*a].name, 
                    sc[*a].krace, sc[*a].kunivrs, sc[*a].kteam, &sc[*a].plevel);
        }
    }
    *aN = *a;
    fclose(ftemp);
}

void readFile(int *a, int *b, atr sc[], char fileName[]){
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    if(*a != 0){
        *a = 0;
    }

    int rval = fscanf(ftemp, "%s %s\n", sc[*a].skey, sc[*a].sname);
    
    if((strcmp(sc[*a].skey, "####") == 0) || rval == EOF){
        printf("File Kosong\n");
    }else{
        while(strcmp(sc[*a].skey, "####") != 0){
            *a = *a +1;
            fscanf(ftemp, "%s %s", sc[*a].skey, sc[*a].sname);
        }
    }

    *b = *a;
    fclose(ftemp);
}

void mMerge(int *aN, int *aR, int *aU, int *aT, atr sc[], char fileName[]){
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

    for(int i = 0; i < *aN; i++){
        fscanf(fFighter, "%s %s %s %s %s %d\n", sc[i].fkey, sc[i].name, 
                sc[i].krace, sc[i].kunivrs, sc[i].kteam, &sc[i].plevel);
        
        for(int j = 0; j < *aR; j++){
            if(strcmp(sc[j].skey, sc[i].krace) == 0){
                strcpy(sc[i].krace, sc[j].sname);
            }
        }
        
        for(int j = 0; j < *aU; j++){
            if(strcmp(sc[j].skey, sc[i].kunivrs) == 0){
                strcpy(sc[i].kunivrs, sc[j].sname);
            }
        }

        for(int j = 0; j < *aT; j++){
            if(strcmp(sc[j].skey, sc[i].kteam) == 0){
                strcpy(sc[i].kteam, sc[j].sname);
            }
        }
    }
    
    int idx = 0;
    while(strcmp(sc[idx].fkey, "####") != 0){
        fprintf(fcFile, "%s %s %s %s %s %d\n", sc[idx].fkey, sc[idx].name,
                sc[idx].krace, sc[idx].kunivrs, sc[idx].kteam, sc[idx].plevel);
        fscanf(fFighter, "%s %s %s %s %s %d\n", sc[idx].fkey, sc[idx].name, 
                sc[idx].krace, sc[idx].kunivrs, sc[idx].kteam, &sc[idx].plevel);
        idx++;
    }
    fprintf(fcFile, "%s %s %s %s %s %d\n", "####", "####", "####", "####", "####", -999); 

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