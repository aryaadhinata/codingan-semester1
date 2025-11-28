#include "header.h"

int main(){
	int m = 0;
	dataName listLagu[50]; // Alokasi data lagu	
	
	// memanggil prosedur read file untuk membaca data dari file
	readFileName(&m, listLagu, "Songs.dat");
	
	// menampilkan data list lagu
	printf("List lagu:\n");
	for(int i = 0; i < m; i++){
		printf("%s %s %d\n", listLagu[i].judul, listLagu[i].musisi, &listLagu[i].tahun);
	}
	return 0;
}