#include <stdio.h>

int fibonacci(int n){
	if(n == 1){
		return 1;
	}else if(n == 0){
		return 0;
	}
	
	return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(){
	int n;
	scanf("%d", &n);
	
	int hasil = fibonacci(n);
	printf("fibonacci ke-%d adalah %d\n", n, hasil);
	return 0;
}