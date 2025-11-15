#include <stdio.h>

int quickSortPivotPinggirTab1(int l, int r, int tabel1[], int tabel1new[]){
	int i; int j; int temp;
	i = l; j = r;
	do{
		while((tabel1[i] < tabel1[r]) && (i <= j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas j */
			i = i + 1;
		}
		while((tabel1[j] > tabel1[l]) &&
			(i<=j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas i */
			j = j - 1;
		}

		if(i<j){
			temp = tabel1[i];
			tabel1[i] = tabel1[j];
			tabel1[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i < j);
	
	if(l < j){
		quickSortPivotPinggirTab1(l, j, tabel1, tabel1new);
	}
	if(i < r){
		quickSortPivotPinggirTab1(i, r, tabel1, tabel1new);
	}
	
	if((l == j) && (i == r)){
		for(int a = 0; a < 5; a++){
			tabel1new[a] = tabel1[a];
		}
		return tabel1new[5];
	}
}

int quickSortPivotPinggirTab2(int l, int r, int tabel2[], int tabel2new[]){
	int i; int j; int temp;
	i = l; j = r;
	do{
		while((tabel2[i] < tabel2[r]) && (i <= j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas j */
			i = i + 1;
		}
		while((tabel2[j] > tabel2[l]) && (i<=j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas i */
			j = j - 1;
		}

		if(i<j){
			temp = tabel2[i];
			tabel2[i] = tabel2[j];
			tabel2[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i < j);
	
	if(l < j){
		quickSortPivotPinggirTab2(l, j, tabel2, tabel2new);
	}
	if(i < r){
		quickSortPivotPinggirTab2(i, r, tabel2, tabel2new);
	}
	
	if((l == j) && (i == r)){
		for(int a = 0; a < 3; a++){
			tabel2new[a] = tabel2[a];
		}
		return tabel2new[3];
	}
}

int main(){
	int tabel1[5];
	int tabel2[3];
	int tabel3[8];
	int penghitung1;
	int penghitung2;
	int penghitung3;
	int penghitung;
	
	// memasukan nilai ke tabel1
	for(penghitung1=0; penghitung1<5; penghitung1++){
		printf("masukkan angka:\n");
		scanf("%d", &tabel1[penghitung1]);
	}
	
	// funsi untuk array baru 1
	int tabel1new[5];
	quickSortPivotPinggirTab1(0, 5, tabel1, tabel1new);
	
	// masukan nilai ke tabel2
	for(penghitung2=0; penghitung2<3; penghitung2++){
		printf("masukkan angka:\n");
		scanf("%d", &tabel2[penghitung2]);
	}

	// fungsi untuk array baru 2
	int tabel2new[3];
	quickSortPivotPinggirTab2(0, 2, tabel2, tabel2new);

	/*inisialisasi indeks awal setiap tabel */
	penghitung1 = 0;
	penghitung2 = 0;
	penghitung3 = 0;
	while((penghitung1 < 5) && (penghitung2 < 3)){
		if(tabel1new[penghitung1] < tabel2new[penghitung2]){
			tabel3[penghitung3] = tabel1new[penghitung1];
			penghitung1 = penghitung1 + 1;
			penghitung3 = penghitung3 + 1;
		}else if(tabel2new[penghitung2] < tabel1new[penghitung1]){
			tabel3[penghitung3] = tabel2[penghitung2];
			penghitung2 = penghitung2 + 1;
			penghitung3 = penghitung3 + 1;
		}else{
			tabel3[penghitung3] = tabel1new[penghitung1];
			penghitung1 = penghitung1 + 1;
			penghitung3 = penghitung3 + 1;
			tabel3[penghitung3] = tabel2new[penghitung2];
			penghitung2 = penghitung2 + 1;
			penghitung3 = penghitung3 + 1;
		}
	}

	if(penghitung1 < 5){
		for(penghitung=penghitung1; penghitung<5; penghitung++){
			tabel3[penghitung3] = tabel1new[penghitung];
			penghitung3 = penghitung3 + 1;
		}
	}

	if(penghitung2 < 3){
		for(penghitung=penghitung2; penghitung<3; penghitung++){
			tabel3[penghitung3] = tabel2new[penghitung];
			penghitung3 = penghitung3 + 1;
		}
	}
	
	for(penghitung = 0; penghitung < 8; penghitung++){
		printf("ke-%d = %d\n", penghitung, tabel3[penghitung]);
	}
	return 0;
}