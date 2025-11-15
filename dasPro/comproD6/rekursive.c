#include <stdio.h>

int faktorial(int n){
	if (n == 1){
		return 1;
	}
	
	return (n * faktorial(n - 1));
}

int main(){
	int n;
	scanf("%d", &n);
	
	int hasil = faktorial(n);
	printf("faktorial dari %d adalah %d\n", n, hasil);
	return 0;
}