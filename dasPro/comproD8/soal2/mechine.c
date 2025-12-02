#include "head.h"

// Prosedur read from Songs.dat
void readFileName(int *n, dataName source[], char fileName[]){
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); // r untuk operator read file
    int returnVal = fscanf(fTemp, "%s %s %d %s %s", source[*n].kode, source[*n].judul, &source[*n].menit, source[*n].genre, source[*n].studio);
    //untuk scan 3 data pada baris pertama dari isi file
    // cek apakah data yang di scan di atas EOF atau tidak
    if(strcmp(source[*n].judul, "####") == 0 || returnVal == EOF) { 
        printf("File Kosong\n");
    } else{ // jika bukan EOF
        while(strcmp(source[*n].judul, "####") != 0){ // selama bukan data EOF
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %d %s %s", source[*n].kode, source[*n].judul, &source[*n].menit, source[*n].genre, source[*n].studio); // scan data dan menampungnya dalam array sesuai index ke-*n, kemudian scan data berikutnya
        }
    }
    fclose(fTemp); // tutup file
}

void writeToFileName(int n, dataName source[], char fileName[]){
    FILE *fTemp;
    fTemp = fopen(fileName, "w"); // Buka file dengan operator write to file
    for(int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s %d %s %s", source[n].kode, source[n].judul, &source[n].menit, source[n].genre, source[n].studio); // write data ke dalam file
    }
    fprintf(fTemp, "%s %s %d %s %s\n", "####", "####", -999, "####", "####"); // write data EOF setelah bikin data dalam file
    fclose(fTemp); // tutup file
}