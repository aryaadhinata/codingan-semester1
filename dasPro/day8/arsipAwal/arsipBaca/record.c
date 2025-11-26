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
	printf("isi arsip matkul:\n");
	fscanf(arsipMatkul, "%s %s %s", rekaman.nim, rekaman.nama, rekaman.nilai);
	
	if(strcmp(rekaman.nim, "XXXXXX") == 0){
		printf("arsip kosong\n");
	}else{
		do{
			printf("nim : %s\n", rekaman.nim);
			printf("nama : %s\n", rekaman.nama);
			printf("nilai : %s\n", rekaman.nilai);
			printf("--------------------------------\n");
			
			fscanf(arsipMatkul, "%s %s %s", rekaman.nim, rekaman.nama, rekaman.nilai);
		}while(strcmp(rekaman.nim, "XXXXXX") != 0);
	}
	
	fclose(arsipMatkul);
	return 0;
}