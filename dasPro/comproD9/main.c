#include <stdio.h>
#include "head.h"

int main(){
    char pita[257];
    printf("Masukan pita yang akan diproses\n");
    scanf("%256[^\n]s", pita);

    START(pita);

    int count = 0;
    while (EOP() == 0){
        printf("%c", GETCC());

        if ((GETCC() == 'k') || GETCC() == 'K'){
            INC(pita);
            if ((GETCC() == 'a') || GETCC() == 'A'){
                INC(pita);
                DEC(pita);
                if ((GETCC() == 'n') || GETCC() == 'N'){
                    count++;
                    DEC(pita);
                }else{
                    DEC(pita);
                }
            }else{
                DEC(pita);
            }
        }
        INC(pita);
    }

    printf("\nJumlah suku kata: %d\n", count);
    return 0;
}