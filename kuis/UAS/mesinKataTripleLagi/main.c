#include "head.h"

int main(){
    char pita[301], current[301], next[301], check[301];
    int flag = 0, jml = 0;
    scanf("%300[^\n]s", &pita);
    
    start(pita);
    strcpy(current, getcw());
    inc(pita);
    strcpy(next, getcw());
    inc(pita);
    strcpy(check, getcw());
    
    while (!eop(pita)){
        jml++;
        if(countKata(current) == countKata(next) + countKata(check)){
            printf("tripel %d\n", jml);
            printf("%s\n", current);
            printf("%s\n", next);
            printf("%s\n", check);
            flag = 1;
        }
        inc(pita);
        strcpy(current, getcw());
        inc(pita);
        strcpy(next, getcw());
        inc(pita);
        strcpy(check, getcw());
    }

    if(flag == 0){
        printf("tidak ada\n");
    }else{
        printf("yang memenuhi syarat: %d pasangan\n", jml);
    }
    
    return 0;
}