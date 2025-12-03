#include <stdio.h>
#include "head.h"

int main(){
    char pita[65];
    printf("Masukan pita yang akan diproses\n");
    scanf("%64[^\n]s", &pita);

    START(pita);
    printf("%c\n", GETCC());

    while (EOP() == 0){
        INC(pita);
        printf("%c\n", GETCC());
    }
    
    return 0;
}