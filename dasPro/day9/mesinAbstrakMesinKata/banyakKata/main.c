#include <stdio.h>
#include "head.h"

int main(){
    char pita[300];
    printf("masukan kalimat anda:\n");
    scanf("%299[^\n]s", pita);

    STARTWORD(pita);
    int Jword = 0;
    while (EOPWORD(pita) == 0){
        Jword++;
        INCWORD(pita);
    }

    if(GETPANJANGKATA() > 0){
        Jword++;
    }

    printf("%d", Jword);
    return 0;
}