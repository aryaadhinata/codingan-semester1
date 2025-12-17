#include <stdio.h>
#include <string.h>

// deklarasi variabel global
int idx; // variabel global untuk indeks karakter
char cc; // variabel global untuk menampung current character

// prosedur untuk memulai mesin karakter
void START(char pita[]){
    // memulai pembacaan mesin karakter
    idx = 0; // index pasti dimulai dari 0
    cc = pita[idx]; // cc adalah pita inputan ke idx = 0
}


// fungsi untuk memeriksa akhir dari proses (End of Process)
int EOP(){
    if(cc == '='){ // jika cc saat ini '.' (eop)
        return 1; // kembalikan nilai 1 (marking eop true)
    }
    else{ // jika tidak
        return 0; // kembalikan nilai 0
    }
}


// prosedur untuk memajukan karakter pada pita
void INC(char pita[]){
    // menambah nilai indeks dan mengatur karakter yang dibaca
    idx++;
    cc = pita[idx];
}


// prosedur untuk memajukan karakter hingga melewati spasi
void ADV(char pita[]){
    // menambah nilai indeks dan mengatur karakter yang dibaca
    idx++;
    cc = pita[idx];


    // proses looping jika karakter saat ini masih berupa spasi
    while((cc == ' ') && (EOP() == 0)){
        idx++;
        cc = pita[idx];
    }
}


// fungsi untuk mendapatkan karakter pita saat ini
char GETCC(){ 
    return cc;
}


// fungsi untuk mendapatkan indeks pita saat ini
int GETIdx(){ 
    return idx;
}

int main(){
    char pita[301];
    char cek;
    int jml, flag = 0, jml_huruf = -1;
    scanf("%300[^\n]s", &pita);
    scanf(" %c %d", &cek, &jml);

    START(pita);

    while(!EOP()){
        // printf("%c %d\n", GETCC(), jml_huruf);
        if(GETCC() != ' '){
            jml_huruf++;
        }
        if(GETCC() == cek){
            printf("%c - %d - %d\n", cek, GETIdx(), (jml_huruf / jml) + 1);
            flag = 1;
        }
        ADV(pita);
    }

    if(flag == 0){
        printf("tidak ketemu\n");
    }

}