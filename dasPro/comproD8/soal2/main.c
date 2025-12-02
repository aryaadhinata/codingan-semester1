#include "head.h"

int main() {
    int m = 0;
    int n = 0;
    dataName film[50]; // Alokasi data lagu
    // Memanggil prosedur read file untuk membaca data dari file
    readFileName( & m, film, "film.txt");

    int i = 0;
    dataName temp[1];
    char masuk[11];
    scanf("%s", masuk);
    if (strcmp(masuk, "INSERT") == 0) { // kode perintah yang di tandai untuk dilaksanakan
        scanf("%s %s %d %s %s", temp[0].kode, temp[0].judul, & temp[0].menit, temp[0].genre, temp[0].studio);
        while (strcmp(temp[0].kode, film[i].kode) == 1 && strcmp(film[i].judul, "####")) { // bagian untuk mencari panjang list
            i = i + 1;
        }
        for (int j = m; i <= j; j--) {
            film[j + 1] = film[j]; // memundurkan dari indeks dari indeks yang lebih besar
        }
        film[i] = temp[0];
    }
    for (int i = 0; i < m + 1; i++) { // looping untuk print ke terminal 
        printf("%s %s %d %s %s\n", film[i].kode, film[i].judul, film[i].menit, film[i].genre, film[i].studio);
    }
    printf("%s %s %d %s %s\n", "####", "####", -999, "####", "####"); // membuat dummy EOF
    printf("%d", i); // menunjukan indeks keberapa yang bergeser

    return 0;
}