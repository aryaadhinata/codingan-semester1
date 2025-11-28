#include "header.h"


int main(){
    int n, m = 0;
    dataName listLagu[50]; // Alokasi data lagu


    // Memanggil prosedur read file untuk membaca data dari file
    readFileName(&m, listLagu, "Songs.dat");


    // Menampilkan data list lagu
    printf("List Lagu:\n");
    for(int i = 0; i < m; i++){
        printf("%s %s %d\n", listLagu[i].judul, listLagu[i].musisi, listLagu[i].tahun);
    }


    char opt[5];
    scanf("%s", opt); // Option, jika ingin menambahkan data, input "y" atau "Y"
    if(strcmp(opt,"y") == 0 || strcmp(opt, "Y") == 0){
       
        // WRITE TO FILE data sebanyak n
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%s", listLagu[i].judul);
            scanf("%s", listLagu[i].musisi);
            scanf("%d", &listLagu[i].tahun);
        }
        writeToFileName(n, listLagu, "Songs.dat");
    }


    return 0;
}
