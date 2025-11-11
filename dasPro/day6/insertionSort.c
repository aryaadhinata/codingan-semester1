#include <stdio.h>

int main(){
	int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
	int i; int data_sisip; int j;
	for(i = 1; i < 10; i++){
		data_sisip = tabInt[i];
		j = i - 1;
		while((data_sisip < tabInt[j]) && (j >= 0)){
			/*jika data array lebih kecil dari data sisip maka data array digeser
			ke belakang*/
			tabInt[j+1] = tabInt[j];
			j = j - 1;
		}
		/*menempatkan data sisip pada array*/
		tabInt[j+1] = data_sisip;
	}
	
	for(int a = 0; a < 10; a++){
		printf("%d ", tabInt[a]);
	}
return 0;
}