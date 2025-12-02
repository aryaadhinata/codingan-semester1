#include "header.h"


int main(){
    int m = 0;
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
       m--; // menetralkan ideks, karena elem pertama harusnya dimulai dari m
	   
        do{ // lakukan sampai kertemu EOF
			m++; // iterasi untuk loop
            scanf("%s", listLagu[m].judul);
            scanf("%s", listLagu[m].musisi);
            scanf("%d", &listLagu[m].tahun);
		}while(strcmp(listLagu[m].judul, "####") != 0); // selama tidak bertemu EOF, loop akan terus berjalan
        
		writeToFileName(m, listLagu, "Songs.dat");
    }


    return 0;
}
