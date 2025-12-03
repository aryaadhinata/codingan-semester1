#include <stdio.h>
#include "head.h"

int main(){
    char pita[300];
    printf("masukan kalimat anda:\n");
    scanf("%299[^\n]s", pita);

    STARTWORD(pita);
    printf("%s\n", GETWORD());
    while (EOPWORD(pita) == 0){
        INCWORD(pita);
        printf("%s\n", GETWORD());
    }

    return 0;
}