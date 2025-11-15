#include <stdio.h>

int main(){
	int tabel1[5];
	int tabel2[3];
	int tabel3[8];
	int penghitung;

	for(penghitung = 0; penghitung < 5;	penghitung++){
		printf("masukkan angka:\n");
		scanf("%d", &tabel1[penghitung]);
	}
	
	for(penghitung = 0; penghitung < 3;	penghitung++){
		printf("masukkan angka:\n");
		scanf("%d", &tabel2[penghitung]);
	}

	for(penghitung = 0; penghitung < 5;	penghitung++){
		tabel3[penghitung] = tabel1[penghitung];
	}

	for(penghitung = 5; penghitung < 8;	penghitung++){
		tabel3[penghitung] = tabel2[penghitung - 5];
	}
	
	for(penghitung = 0; penghitung < 8; penghitung++){
		printf("ke-%d = %d\n", penghitung, tabel3[penghitung]);
	}
	return 0;
}