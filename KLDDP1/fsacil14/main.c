#include <stdio.h>

int main(){
	float arrFlo[4];
	int arrInt[4];
	
	for(int i = 0; i < 4; i++){
		scanf("%f", arrFlo[i]);
		scanf("%d", arrInt[i]);
	}
	
	int arrFloBel[4];
	for(int i = 0; i < 4; i++){
		arrFloBel[i] = (int) (arrFlo[i] * 100) % 100; 
	}
	
	return 0;
}