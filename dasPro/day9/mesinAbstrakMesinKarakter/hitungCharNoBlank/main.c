#include <stdio.h>
#include "head.h"

int main(){
    char pita[65];
    printf("Masukan pita yang akan diproses\n");
    scanf("%64[^\n]s", &pita);

    START(pita);

    int count = 0;
    while (EOP() == 0){
        count++;
        ADV(pita);
    }
    
    printf(":%d: karakter terbaca\n", count);
    return 0;
}