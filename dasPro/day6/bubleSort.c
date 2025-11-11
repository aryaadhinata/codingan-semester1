#include <stdio.h>

int main(){
	int tabInt[5] = {34, 67, 23, 28, 98};
	int i; int temp; int tukar;
	do{
		/*inisialisasi nilai tukar sebelum ada pertukaran diset false */
		tukar = 0;
		/*pengulangan dan memeriksa apakah ada pertukaran */
			for(i=0; i<(5-1); i++){
			/*jika ada nilai yang dipertukarkan */
			if(tabInt[i] > tabInt[i+1]){
				/* menukar posisi elemen */
				temp = tabInt[i];
				tabInt[i] = tabInt[i+1];
				tabInt[i+1] = temp;
				tukar = 1;
			}
		}
	}while(tukar == 1);
	
	for(int a = 0; a < 5; a++){
		printf("%d ", tabInt[a]);
	}
	return 0;
}