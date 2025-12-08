#include "head.h"

int main(){
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

    char inp[129];

    printf("=====================================================\n");
    printf("Daftar Perintah\n");
    printf("1. INSERT\n");
    printf("2. UPDATE\n")
    printf("=====================================================\n");
    do{
        printf("Jika ingin berhentik ketik 'No'\n");
        printf(">> ");
        scanf("%s", inp);
        printf("\n");
        if((strcmp(inp, "INSERT") == 0 )|| (strcmp(inp, "1") == 0 )){
            INSf(aN, aR, aU, aT, fighter);
        }else if((strcmp(inp, "UPDATE") == 0) || (strcmp(inp, "2") == 0)){
            UPDf(aN, aR, aU, aT, fighter);
        }else{
            printf(Input tidak sesuai!\n);
        }

        refresh();
    }while((strcmp(inp, "no") != 0) && (strcmp(inp, "No") != 0) &&
            (strcmp(inp, "n") != 0) && (strcmp(inp, "N") != 0));
    return 0;
}