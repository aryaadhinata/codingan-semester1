#include <stdio.h>

int main(){
	float arrFlo[3];
	for(int i = 0; i < 3; i++){
		scanf("%f", &arrFlo[i]);
	}
	
	int arrInt[3];
	for(int i = 0; i < 3; i++){
		scanf("%d", &arrInt[i]);
	}
	
	int arrFloDep[3];
	int arrFloBel[3];
	for(int i = 0; i < 3; i++){
		arrFlo[i] = arrFlo[i]/10;
		arrFloDep[i] = (int) arrFlo[i]; 
		arrFloBel[i] = (int) (arrFlo[i]*100) % 100;
	}
	
	int count = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if((arrFloDep[i]%arrInt[j] == 0) && (arrFloBel[i]%arrInt[j] == 0)){
				count++;
			}
		}
	}

	if(count >= 2){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}