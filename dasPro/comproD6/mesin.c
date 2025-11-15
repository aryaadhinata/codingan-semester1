#include "latsol1Power"

int power(int n, int m, int p){
	if(m < p){// m jadi batas
		return 0;
	}

	int hasil = pow(n, p); // library math
	printf("%d\n", hasil);
	
	return (power(n, m, (p + 1)));//rekursif p jadi nilai pangkat yang terus bertambah
}
