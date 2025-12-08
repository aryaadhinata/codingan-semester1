#include "head.h"

void mReadFile(int *a, int *aN, atr obj[], char fileName[]){ // membaca file utama
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    int rval = fscanf(ftemp, "%s %s %s %s %s %d\n", obj[*a].fkey, obj[*a].name, 
                    obj[*a].krace, obj[*a].kunivrs, obj[*a].kteam, &obj[*a].plevel);
    
    if((strcmp(obj[*a].fkey, "####") == 0) || rval == EOF){ // menghindari file kosong
        printf("File Kosong\n");
    }else{
        while(strcmp(obj[*a].fkey, "####") != 0){
            *a = *a +1;
            fscanf(ftemp, "%s %s %s %s %s %d\n", obj[*a].fkey, obj[*a].name, 
                    obj[*a].krace, obj[*a].kunivrs, obj[*a].kteam, &obj[*a].plevel); // membaca isi file
        }
    }
    *aN = *a; // memindahkan nilai banyak data dalam file ini
    fclose(ftemp);
}

void readFile(int *a, int *b, int *tF, atr obj[], char fileName[]){ // membaca file sampingan
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    if(*a != 0){ // memulai indeks dari 0 lagi
        *a = 0;
    }

    int rval = fscanf(ftemp, "%s %s\n", obj[*a].skey, obj[*a].sname);
    
    if((strcmp(obj[*a].skey, "####") == 0) || rval == EOF){ // menghindari file kosong
        printf("File Kosong\n");
    }else{
        while(strcmp(obj[*a].skey, "####") != 0){
            *a = *a +1;
            fscanf(ftemp, "%s %s", obj[*a].skey, obj[*a].sname); // membaca isi file
        }
    }

    *b = *a; // memindahakan nilai banyak data dalam file ini
    *tF = (*tF % 3) + 1; // menandai pebacaan keberapa
    fclose(ftemp);
}

void mMerge(int *aN, int *aR, int *aU, int *aT, int *tF, atr obj[], char fileName[]){ // mengabungkan file
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
        fscanf(fFighter, "%s %s %s %s %s %d\n", obj[i].fkey, obj[i].name, 
                obj[i].krace, obj[i].kunivrs, obj[i].kteam, &obj[i].plevel); // membaca file utama
        
        switch (*tF){ // kondisi untuk melakukan pergantian skey dengan namanya
            case 1:{ // case file Race.txt
                for(int j = 0; j < *aR; j++){
                    if(strcmp(obj[j].skey, obj[i].krace) == 0){
                        strcpy(obj[i].srace, obj[j].sname);
                    }
                }
                break;
            }case 2:{ // case file Universe.txt
                for(int j = 0; j < *aU; j++){
                    if(strcmp(obj[j].skey, obj[i].kunivrs) == 0){
                        strcpy(obj[i].sunivrs, obj[j].sname);
                    }
                }
                break;
            }case 3:{ // case file Team.txt
                for(int j = 0; j < *aT; j++){
                    if(strcmp(obj[j].skey, obj[i].kteam) == 0){
                        strcpy(obj[i].steam, obj[j].sname);
                    }
                }
                break;
            }
        }
        fprintf(fcFile, "%s %s %s %s %s %d\n", obj[i].fkey, obj[i].name,
                obj[i].srace, obj[i].sunivrs, obj[i].steam, obj[i].plevel); // digabungkan ke FighterComplete.txt
    }
    
    fprintf(fcFile, "%s %s %s %s %s %d\n", "####", "####", "####", "####", "####", -999); // dummy or EOF

    fclose(fcFile);
    fclose(fFighter);
    fclose(fRace);
    fclose(fUnivrs);
    fclose(fTeam);
}

void refresh(){ // digunakan untuk memperbaharui data
        int a = 0, 
        aN = 0, aR = 0, 
        aU = 0, aT = 0,
        tF = 0;
    atr fighter[65];

    mReadFile(&a, &aN, fighter, "Fighter.txt");

    readFile(&a, &aR, &tF, fighter, "Race.txt");
    mMerge(&aN, &aR, &aU, &aT, &tF, fighter, "FighterComplete.txt");

    readFile(&a, &aU, &tF, fighter, "Universe.txt");
    mMerge(&aN, &aR, &aU, &aT, &tF, fighter, "FighterComplete.txt");

    readFile(&a, &aT, &tF, fighter, "Team.txt");
    mMerge(&aN, &aR, &aU, &aT, &tF, fighter, "FighterComplete.txt");
}

void INSm(int n, atr obj[], char fileName[]){
    atr temp[65], new;

    printf("Masukan data: ");
    scanf("%s %s %s %s %s %d", new.fkey, new.name, new.krace, 
        new.kunivrs, new.kteam, &new.plevel);

    FILE *ftemp;
    ftemp = fopen(fileName, "r");
    for(int i = 0; i < n; i++) {
        fscanf(ftemp, "%s %s %s %s %s %d\n", obj[i].fkey, obj[i].name, 
                obj[i].krace, obj[i].kunivrs, obj[i].kteam, &obj[i].plevel);
    }

    int a = 0;
    do{
        temp[a] = obj[a];
        a++;
    }while(strcmp(obj[a].fkey, "####") != 0);
    
    fclose(ftemp);

    if(strcmp(new.fkey, temp[0].fkey) < 0){
        for(int i = n-1; i >= 0; i--) {
            temp[i+1] = temp[i];
        }
        a++;
        temp[0] = new;
    }else if(strcmp(new.fkey, temp[a-1].fkey) > 0){
        temp[a] = new;
        a++;
    }else{
        int k = 0, stop = 0;
        while((k < a) && (stop == 0)){
            if(strcmp(temp[k].fkey, new.fkey) > 0){
                stop = 1;
            }else{
                k++;
            }
        }

        for(int l = a-1; l >= k; l--) {
            temp[l+1] = temp[l];
        }
        temp[k] = new;
    }

    ftemp = fopen(fileName, "w");
    for(int i = 0; i < a; i++) {
        fprintf(ftemp, "%s %s %s %s %s %d\n", temp[i].fkey, temp[i].name, 
                temp[i].krace, temp[i].kunivrs, temp[i].kteam, temp[i].plevel);
    }
    fprintf(ftemp, "%s %s %s %s %s %d\n", "####", "####", "####", "####", "####", -999);
    fclose(ftemp);
}

void INS(int n, atr obj[], char fileName[]){
    atr temp[65], new;

    printf("Masukan data: ");
    scanf("%s %s", new.skey, new.sname);

    FILE *ftemp;
    ftemp = fopen(fileName, "r");
    for(int i = 0; i < n; i++) {
        fscanf(ftemp, "%s %s\n", obj[i].skey, obj[i].sname);
    }

    int a = 0;
    do{
        temp[a] = obj[a];
        a++;
    }while(strcmp(obj[a].skey, "####") != 0);
    
    fclose(ftemp);

    if(strcmp(new.skey, temp[0].skey) < 0){
        for(int i = n-1; i >= 0; i--) {
            temp[i+1] = temp[i];
        }
        a++;
        temp[0] = new;
    }else if(strcmp(new.skey, temp[a-1].skey) > 0){
        temp[a] = new;
        a++;
    }else{
        int k = 0, stop = 0;
        while((k < a) && (stop == 0)){
            if(strcmp(temp[k].skey, new.skey) > 0){
                stop = 1;
            }else{
                k++;
            }
        }

        for(int l = a-1; l >= k; l--) {
            temp[l+1] = temp[l];
        }
        temp[k] = new;
    }

    ftemp = fopen(fileName, "w");
    for(int i = 0; i < a; i++) {
        fprintf(ftemp, "%s %s %s %s %s %d\n", temp[i].skey, temp[i].sname);
    }
    fprintf(ftemp, "%s %s\n", "####", "####");
    fclose(ftemp);
}

void INSf(int aN, int aR, int aU, int aT, atr obj[]){
    char comd[129];

    printf("Masukan nama file:\n");
    printf(">>> ");
    scanf("%s", comd);
    printf("\n");

    if(strcmp(comd, "Fighter.txt") == 0){
        INSm(aN, obj, "Fighter.txt");
    }else if(strcmp(comd, "Race.txt") == 0){
        INS(aR, obj, "Race.txt");
    }else if(strcmp(comd, "Universe.txt") == 0){
        INS(aU, obj, "Universe.txt");
    }else if(strcmp(comd, "Team.txt")){
        INS(aT, obj, "Team.txt");
    }else{
        printf("File tidak ditemukan!\n");
    }
}

void UPDf(int aN, int aR, int aU, int aT, atr obj[]){
        char comd[129];

    printf("Masukan nama file:\n");
    printf(">>> ");
    scanf("%s", comd);
    printf("\n");

    if(strcmp(comd, "Fighter.txt") == 0){
        UPDm(aN, obj, "Fighter.txt");
    }else if(strcmp(comd, "Race.txt") == 0){
        UPD(aR, obj, "Race.txt");
    }else if(strcmp(comd, "Universe.txt") == 0){
        UPD(aU, obj, "Universe.txt");
    }else if(strcmp(comd, "Team.txt")){
        UPD(aT, obj, "Team.txt");
    }else{
        printf("File tidak ditemukan!\n");
    }
}