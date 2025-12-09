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
    printf("                Daftar Perintah\n");
    printf("1. INSERT\n");
    printf("2. UPDATE\n");
    printf("3. DELETE\n");
    printf("4. SELECT\n");
    printf("=====================================================\n");
    do{
        printf("Jika ingin berhentik ketik 'Yes'\n");
        printf(">> ");
        scanf("%s", inp);
        printf("\n");
        if((strcmp(inp, "INSERT") == 0 )|| (strcmp(inp, "1") == 0 )){
            INSf(aN, aR, aU, aT, fighter);
        }else if((strcmp(inp, "UPDATE") == 0) || (strcmp(inp, "2") == 0)){
            UPDf(aN, aR, aU, aT, fighter);
        }else if((strcmp(inp, "DELETE") == 0) || (strcmp(inp, "3") == 0)){
            DELf(aN, aR, aU, aT, fighter);
        }else if((strcmp(inp, "SELECT") == 0) || (strcmp(inp, "4") == 0)){
            SELf(aN, aR, aU, aT, fighter);
        }else if((strcmp(inp, "yes") != 0) && (strcmp(inp, "Yes") != 0) &&
            (strcmp(inp, "y") != 0) && (strcmp(inp, "Y") != 0)){
            printf("Input tidak sesuai!\n");
        }

        refresh();
    }while((strcmp(inp, "yes") != 0) && (strcmp(inp, "Yes") != 0) &&
            (strcmp(inp, "y") != 0) && (strcmp(inp, "Y") != 0));
    return 0;
}