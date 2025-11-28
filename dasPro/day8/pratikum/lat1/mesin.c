#include "header.h"

// prosedur untuk menbaca dari file song.dat
void readFileName(int *n, dataName source[], char fileName[]){
	FILE *fTemp;
	fTemp = fopen(fileName, "r");

	// untuk scan 3 data setiap baris dari isi fie
	int returnVal = fscanf(fTemp, "%s %s %d", source[*n].judul, source[*n].musisi, &source[*n].tahun);
	
	// cek apakah ada data yang di scan di atas EOF atau tidak
	if(strcmp(source[*n].judul, "####") == 0 || returnVal == EOF){
		printf("File kosong\n");
	}else{ // jika bukan EOF
		while(strcmp(source[*n].judul, "####") != 0){ // selama bukan data EOF
				*n = *n + 1;
				fscanf(fTemp, "%s %s %d", source[*n].judul, source[*n].musisi, &source[*n].tahun);
		}
	}
	
	fclose(fTemp);
}