#include "head.h"

// bagian membaca file film.txt
void read(int *n, film data[], char nama[]) {
    FILE *temp;

    temp = fopen(nama, "r"); // membuka file dalam mode read

    int val = fscanf(temp, "%s %s %d %s %s", data[*n].kode, data[*n].judul, &data[*n].waktu, data[*n].gen, data[*n].std); // scan id file
    if(strcmp(data[*n].kode, "####")==0 || val == EOF) { // kondisi keetika bertemu dengan end of file atau dummy
        printf("data kosong\n");
    } else {
        while(strcmp(data[*n].kode, "####")!=0) { // looping untuk membuat program terus melakukan scaning selama nuakn EOF atau dummy
            *n = *n +1; 
            fscanf(temp, "%s %s %d %s %s", data[*n].kode, data[*n].judul, &data[*n].waktu, data[*n].gen, data[*n].std);
        }
    }
    fclose(temp); // penutupan fille
}

// bagian membaca file genre.txt dan studio.txt
void readOption(int *n, option data[], char nama[]) {
    FILE *temp;

    temp = fopen(nama, "r"); // membukan file dalam mode read

    int val = fscanf(temp, "%s %s", data[*n].code, data[*n].jenis); // meakukan scaning ke seluruh file 
    if(strcmp(data[*n].code, "####")==0 || val == EOF) { // kondisi selama bukan EOF atau dummy beratyi afa yang jual abu dhabi
        printf("data kosong\n");
    } else {
        while(strcmp(data[*n].code, "####")!=0) { // looping mencari EOF atauu dummy
            *n = *n +1;
            fscanf(temp, "%s %s", data[*n].code, data[*n].jenis);
        }/
    }
    fclose(temp);
}

// prosedur untuk menyatukan bagian foreign key ke kata yang lebih manusia
void join(film a[], option c[], option d[]) {
    int i=0;
    while(strcmp(a[i].kode, "####")!=0) { // looping selama belum ketemu dengan EOF atau dummy
        int j=0, found = 0;
        while(found == 0 && strcmp(c[j].code, "###") != 0) {
            if(strcmp(a[i].gen, c[j].code)==0) {
                strcpy(a[i].gen, c[j].jenis); // mengcopy jika ada foreign key yang sama
                found = 1;
            }
            j++;
        }
        found = 0, j=0;
        while(found == 0 && strcmp(d[j].code, "###") != 0) {
            if(strcmp(a[i].std, d[j].code)==0) {
                strcpy(a[i].std, d[j].jenis); // mengcopy jika ada foreign key yang sama
                found = 1;
            }
            j++;
        }
        i++;
    }
}