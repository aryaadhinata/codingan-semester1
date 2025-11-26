#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[17];
	char nama[129];
	char nilai[3];
}nilaiMatkul;

int main(){
	nilaiMatkul rekaman;
	FILE *arsipMatkul;
	
	arsipMatkul = fopen("ArsipMatkul.dat", "r");
	char kata_cari[17];
	printf("Masukan nama nim yang dicari: \n");
	scanf("%s", kata_cari);
	
	fscanf(arsipMatkul, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
	
	if(strcmp(kata_cari, "XXXXXX") == 0){
		printf("arsip kosong\n");
	}else{
		if(strcmp(rekaman.nim, "XXXXXX") == 0){
			printf("tidak ditemukan\n");
		}
		else{
			while((strcmp(rekaman.nim, "XXXXXX") != 0) && (strcmp(rekaman.nim, kata_cari) != 0)){
				fscanf(arsipMatkul, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
			}
			if(strcmp(rekaman.nim, kata_cari) == 0){
				printf("nim : %s\n", rekaman.nim);
				printf("nama : %s\n", rekaman.nama);
				printf("nilai : %s\n", rekaman.nilai);
				printf("--------------------------------\n");
			}else{
				printf("tidak ditemukan\n");
			}
		}
	}	
	fclose(arsipMatkul);
	
	return 0;
}