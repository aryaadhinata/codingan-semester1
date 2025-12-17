#include "head.h"

// cek eop
int eop(char pita[]){
    if(pita[idx] == '*'){ // jika '.' return 1
        return 1;
    }
    else{
        return 0; // jika bukan '.' kembalikan 0
    }
}

// nyalakan mesin
void start(char pita[]){
    // set index dan panjang kata menjadi 0
    idx = 0;
    wlen = 0;


    while (pita[idx] == ' '){ // ignore blank
        idx++;
    }


    // ambil kata masukkan dalam current word
    while ((pita[idx] != ' ') && (eop(pita) == 0)){
        cw[wlen] = pita[idx];
        wlen++;
        idx++;
    }
    cw[wlen] = '\0'; // akhiri dengan null terminator
}


// reset current word
void reset(){
    wlen = 0; // kembalikan panjang kata menjadi 0
    cw[wlen] = '\0'; // set current word menjadi null (siap diisi)
}

// pindah next kata
void inc(char pita[]){
    wlen = 0; // set panjang kata jadi 0 (memastikan)


    while (pita[idx] == ' '){ // ignore blank
        idx++;
    }


    // masukkan kata baru
    while ((pita[idx] != ' ') && (eop(pita) == 0)){
        cw[wlen] = pita[idx];
        wlen++;
        idx++;
    }
    cw[wlen] = '\0'; // akhiri lagi
}

int countKata(char pita[]){
    int count = 0;
    int len = strlen(pita);
    for(int i = 0; i < len; i++) {
        if(cw[i] == 'a' || cw[i] == 'i' || cw[i] == 'u' || cw[i] == 'e' || cw[i] == 'o'){
            count++;
        }
    }

    return count;
}

// mengembalikan current word
char* getcw(){
    return cw;
}


// mengembalikan panjang current word
int getlen(){
    return wlen;
}