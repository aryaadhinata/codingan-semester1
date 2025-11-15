#include <stdio.h>

int sort(int l, int r, int arr[]){
	int i; int j; int temp;
	i = l; j = r;
	do{
		while((arr[i] < arr[r]) && (i <= j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas j */
			i = i + 1;
		}
		while((arr[j] > arr[l]) &&
			(i<=j)){
			/* mencegah i berjalan terlalu
			jauh melewati batas i */
			j = j - 1;
		}

		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i < j);
	if(l < j){
		sort(l , j, arr);
	}
	if(i < r){
		sort(i , r, arr);
	}
	if((i == r) && (l == j)){
	return arr[r];
	}
}

void mergeArr(int n, int arr1[], int n2, int arr2[], int arr3[]){
    // deklarasi dan inisialisasi index untuk ketiga array
    int idx1 = 0, idx2 = 0, idx3 = 0;
    // loop sampai arr1 atau arr2 habis (salah satunya dulu)
    while(idx1 < n && idx2 < n2){
        // jika elemen arr1 lebih kecil dari arr2
        if(arr1[idx1] < arr2[idx2]){
            // masukan elemen tersebut ke arr3
            arr3[idx3] = arr1[idx1];
            idx1++;
        }else{
        // jika elemen arr2 lebih kecil dari arrar
            // masukan elemen tersebut ke arr3
            arr3[idx3] = arr2[idx2];
            idx2++;
        }
        // iterasi untuk index arr3
        idx3++;
    }


    // jika ada sisa di arr1, maka masukan ke arr3
    while(idx1 < n){
        arr3[idx3] = arr1[idx1];
        idx1++;
        idx3++;
    }
    // jika ada sisa di arr2, maka masukan ke arr3
    while(idx2 < n2){
        arr3[idx3] = arr2[idx2];
        idx2++;
        idx3++;
    }
}

int main(){
	int n, n2;
    scanf("%d %d", &n, &n2);
    int arr1[n];
    int arr2[n2];
   
    for(int i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }
	
	sort(0, n, arr1);
	sort(0, n2, arr2);


    int arr3[n+n2];
    mergeArr(n, arr1, n2, arr2, arr3);


    for(int i = 0; i < n+n2; i++){
        printf("%d ", arr3[i]);
    }
    printf("\n");

	return 0;
}