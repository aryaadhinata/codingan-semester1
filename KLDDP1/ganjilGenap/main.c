#include <stdio.h>

int main() {
    int arr[6]; // array awal
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }
	
	int gen = 0, gan = 0 arrGan[4], arrGen[4];
	for(int i = 0; i < 6; i++){
		if(arr[i] % 2 == 0) { // batas char angka
			arrGen[gen] = arr[i]; // array angka
			gen++;
		}else if(arr[i] % 2 == 1){ // batas char huruf
			arrGan[gan] = arr[i]; // array huruf
			gan++;
		}
	}
	
	if((alpha == 3) && (ang == 3)){ 
		for(int i = 0; i < 3; i++){
			printf("%d\n", arrGan[i]);
			printf("%d\n", arrGen[i]);
		}
	}else{
		printf("tidak valid\n");
	}
	
	return 0;
}