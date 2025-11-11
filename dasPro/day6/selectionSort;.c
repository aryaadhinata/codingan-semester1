#include <stdio.h>

int main(){
	int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
	int i; int temp; int minIndeks; int j;
	for(i=0; i<(10-1); i++){
		/*inisialisasi indeks elemen minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen
		array*/
		for(j=(i + 1); j<10; j++){
			if(tabInt[minIndeks] > tabInt[j]){
				minIndeks = j;
				}
			}
		//menukar posisi elemen
		temp = tabInt[i];
		tabInt[i] = tabInt[minIndeks];
		tabInt[minIndeks] = temp;
	}
	
	for(int a = 0; a < 10; a++){
		printf("%d ", tabInt[a]);
	}
return 0;
}