#include "head.h"

void start(char pita[]){
    idx = 0;
    wlen = 0;

    while(pita[idx] == ' '){
        idx++;
    }

    while((pita[idx] != ' ') && (eop(pita) == 0)){
        cw[wlen] = pita[idx];
        wlen++;
        idx++;
    }
    cw[wlen] = '\0';
}

void reset(){
    wlen = 0;
    cw[wlen] = '\0';
}

int eop(char pita[]){
    
}