#include <stdio.h>

int main(){
	float arrFlo[3];
	int arrInt[3];
	
	for(int i = 0; i < 3; i++){
		scanf("%f", &arrFlo[i]);
	}

	for(int i = 0; i < 3; i++){
		scanf("%d", &arrInt[i]);
	}
	
	int arrFloBel[3];
	for(int i = 0; i < 3; i++){
		arrFloBel[i] = (int) (arrFlo[i] * 100) % 100; 
	}
	
	int count = 0;
	for(int i = 0; i < 3; i++){
		if((arrFloBel[i] / arrInt[i] == 0) && (arrFlo[i] / arrInt[i] == 0)){
			count++;
		}
	}
	return 0;
}