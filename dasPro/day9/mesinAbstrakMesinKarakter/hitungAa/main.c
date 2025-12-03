#include <stdio.h>
#include "head.h"

int main(){
    char pita[51];
    printf("Masukan pita yang akan diproses\n");
    scanf("%50[^\n]s", pita);

    START(pita);

    while (EOP() == 0){
        if ((GETCC() == 'a') || GETCC() == 'A'){
            printf("%c == %d\n", GETCC(), GETINDEX());
        }
        INC(pita);
    }

    return 0;
}