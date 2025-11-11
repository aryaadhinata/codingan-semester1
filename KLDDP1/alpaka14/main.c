#include <stdio.h>

int main() {
    char arr[6]; // array awal
    for (int i = 0; i < 6; i++) {
        scanf(" %c", &arr[i]);
    }
	
	int alpha = 0, ang = 0;
	char  arrAlp[4], arrAng[4];
	for(int i = 0; i < 6; i++){
		if((arr[i] <= 57) && (arr[i] >= 48)) { // batas char angka
			arrAng[ang] = arr[i]; // array angka
			ang++;
		}else if(((arr[i] <= 65) && (arr[i] >= 90)) || ((arr[i] >= 96) && (arr[i] <= 122))){ // batas char huruf
			arrAlp[alpha] = arr[i]; // array huruf
			alpha++;
		}
	}
	
	if((alpha == 3) && (ang == 3)){ 
		for(int i = 0; i < 3; i++){
			printf("%c\n", arrAlp[i]);
			printf("%c\n", arrAng[i]);
		}
	}else{
		printf("tidak valid\n");
	}
	
	return 0;
}