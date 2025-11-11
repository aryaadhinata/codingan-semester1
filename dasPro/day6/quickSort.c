#include <stdio.h>

int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};

void tulis(){
	int i;
	for(i=0; i<10; i++){
		printf("%d ", tabInt[i]);
	}
	printf("\n");
}

void quickSortPivotPinggir(int l, int r){
	int i; int j; int temp;
	i = l; j = r;
	do{
		while((tabInt[i] < tabInt[r]) && (i<=j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas j */
			i = i + 1;
		}
		while((tabInt[j] > tabInt[l]) &&
			(i<=j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas i */
			j = j - 1;
		}

		if(i<j){
			temp = tabInt[i];
			tabInt[i] = tabInt[j];
			tabInt[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i<j);
	tulis();
	if(l < j){
		quickSortPivotPinggir(l,j);
	}
	if(i<r){
		quickSortPivotPinggir(i,r);
	}
}

int main(){
	tulis();
	quickSortPivotPinggir(0, 9);
	return 0;
}