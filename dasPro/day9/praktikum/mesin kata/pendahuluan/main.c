#include "head.h"

int main(){
    char pita[50];
    scanf("%49[^\n]s", &pita);
    
    start(pita);
    
    while(eop(pita) == 0){
        printf("%s\n", getcw());
        inc(pita);
    }
    printf("%s", getcw());
    
    return 0;
}