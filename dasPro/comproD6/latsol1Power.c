#include "latsol1Power.h"

int main(){
	int n, m, p = 1; // p = pangkat di mulai dari 1
	scanf("%d %d", &n, &m);
	
	power(n, m, p);// masuk ke rekursif
	return 0;
}