#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	char nama[n][51];
	int ukrFile[n];
	for(int i = 0; i < n; i++){
		scanf("%s %d", nama[i], ukrFile[i]);
	}
	
	for(int i = 0; i < n; i++){
		printf("%s %d\n", nama[i], ukrFile[i]);
	}
	
	
	return 0;
}