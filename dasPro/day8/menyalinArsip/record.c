#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[17];
	char nama[129];
	char nilai[3];
}nilaiMatkul;

int main(){
	nilaiMatkul rekaman;
	FILE *arsipMatkul1;
	FILE *arsipMatkul2;
	
	arsipMatkul1 = fopen("ArsipMatkul.dat", "r");
	arsipMatkul2 = fopen("ArsipMatkul.bak", "w");
	printf("mulai proses menyalin file\n");
	
	fscanf(arsipMatkul1, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
	
	if(strcmp(rekaman.nim, "XXXXXX") == 0){
		fprintf(arsipMatkul2, "%s %s %s\n", "XXXXXX", "XXXX", "XX");
	}else{
		while(strcmp(rekaman.nim, "XXXXXX") != 0){
			fprintf(arsipMatkul2, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
			fscanf(arsipMatkul1, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
		}
		
		fprintf(arsipMatkul2, "%s %s %s\n", "XXXXXX", "XXXX", "XX");
	}
	printf("proses menyalin file selesai:\n");
	
	fclose(arsipMatkul1);
	fclose(arsipMatkul2);
	
	return 0;
}