#include <stdio.h>
#include <string.h>


int idx; // index
int wlen; // panjang current word
char cw[51]; // current word

// cek eop
int eop(char pita[]){
    if(pita[idx] == '='){ // jika '.' return 1
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


// mengembalikan current word
char* getcw(){
    return cw;
}


// mengembalikan panjang current word
int getlen(){
    return wlen;
}

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
        if(!eop(pita) && ((current[1] == 'a' || current[1] == 'i' || current[1] == 'u' || current[1] == 'e' || current[1] == 'o') && (current[strlen(current) - 2] == 'a' || current[strlen(current) - 2] == 'i' || current[strlen(current) - 2] == 'u' || current[strlen(current) - 2] == 'e' || current[strlen(current) - 2] == 'o') && (check[1] == 'a' || check[1] == 'i' || check[1] == 'u' || check[1] == 'e' || check[1] == 'o') && (check[strlen(check) - 2] == 'a' || check[strlen(check) - 2] == 'i' || check[strlen(check) - 2] == 'u' || check[strlen(check) - 2] == 'e' || check[strlen(check) - 2] == 'o'))){
            printf("%s %s\n", current, check);
            flag = 1;
            jml++;
            inc(pita);
            strcpy(current, getcw());
            inc(pita);
            strcpy(next, getcw());
            inc(pita);
            strcpy(check, getcw());
        }else{
            inc(pita);
            strcpy(current, next);
            strcpy(next, check);
            strcpy(check, getcw());
        }
    }

    if(flag == 0){
        printf("tidak ada\n");
    }else{
        printf("yang memenuhi syarat: %d pasangan\n", jml);
    }
    
}