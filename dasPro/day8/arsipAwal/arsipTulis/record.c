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
	
	arsipMatkul = fopen("ArsipMatkul.dat", "w");
	printf("Tuliskan rekaman satu persatu:\n");
	printf("Masukan nama nim: \n");
	scanf("%s", &rekaman.nim);
	
	while(strcmp(rekaman.nim, "XXXXXX") != 0){
		printf("masukan nama: \n");
		scanf("%s", rekaman.nama);
		printf("masukan nilai: \n");
		scanf("%s", rekaman.nilai);
		
		fprintf(arsipMatkul, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
		
		printf("Masukan nama nim: \n");
		scanf("%s", &rekaman.nim);
	}
	
	fprintf(arsipMatkul, "%s %s %s\n", "XXXXXX", "XXXXX", "XX");
	
	
	fclose(arsipMatkul);
	return 0;
}