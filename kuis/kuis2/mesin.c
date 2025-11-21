#include "markse.h"

/*
	fungsi yang digunakan untuk menemukan nilai quality yang akan digunakan nantinya
*/
int kualitas(bio arr){
	int nilai = (arr.portoHard - arr.nganggur) + (arr.portoSoft - arr.nganggur);
	return nilai;
}

/*
	sorting dengan mengunakan quick
*/
int quickSortPivotPinggir(int l, int r, bio arr[]){
	int i; int j; bio temp;
	i = l; j = r;

	do{
		/*
			pengkondisian untukk bagian pengurutan untuk i
		*/
		while((arr[i].quality > arr[r].quality) && (i <= j)){
			// mencegah i berjalan terlalu jauh melewati batas j
			i = i + 1;
		}
		
		/*
			pengkondisian untukk bagian pengurutan untuk j
		*/
		while((arr[j].quality < arr[l].quality) && (i <= j)){
			// mencegah i berjalan terlalu jauh melewati batas i
			j = j - 1;
		}

		/*
			bagian penukaran
		*/
		if(i < j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i < j);
	
	/*
		bagian untuk merekursif
	*/
	if(l < j){
		quickSortPivotPinggir(l, j, arr);
	}
	if(i < r){
		quickSortPivotPinggir(i, r, arr);
	}
}

/*
	sorying lainya yang saya gunakan selectionSort
*/
void selectionSort(int arr_idx, bio arr[]){
	int i, minIndeks, j;
	bio temp;
	for(i = 0; i < (arr_idx-1); i++){
		/*inisialisasi indeks elemen minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen
		array*/
		for(j= (i + 1); j < arr_idx; j++){
			if(arr[minIndeks].quality < arr[j].quality){
				minIndeks = j;
				}
			}
		//menukar posisi elemen
		temp = arr[i];
		arr[i] = arr[minIndeks];
		arr[minIndeks] = temp;
	}
}

/*
	bagain untuk menggabungkan array
*/
void mergeArr(int first, int second, bio satu[], bio dua[], bio arrMerge[]){
	// deklarasi dan inisialisasi index untuk ketiga array
    int idx1 = 0, idx2 = 0, idx3 = 0;
    // loop sampai arr1 atau arr2 habis (salah satunya dulu)
    while(idx1 < first && idx2 < second){
        // jika elemen arr1 lebih kecil dari arr2
        if(satu[idx1].quality > dua[idx2].quality){
            // masukan elemen tersebut ke arr3
            arrMerge[idx3] = satu[idx1];
            idx1++;
        }else{
        // jika elemen arr2 lebih kecil dari arrar
            // masukan elemen tersebut ke arr3
            arrMerge[idx3] = dua[idx2];
            idx2++;
        }
        // iterasi untuk index arr3
        idx3++;
    }


    // jika ada sisa di arr1, maka masukan ke arr3
    while(idx1 < first){
        arrMerge[idx3] = satu[idx1];
        idx1++;
        idx3++;
    }
    // jika ada sisa di arr2, maka masukan ke arr3
    while(idx2 < second){
        arrMerge[idx3] = dua[idx2];
        idx2++;
        idx3++;
    }
}

/*
	bagian untuk binnary search dan mengembalikan nilai jika ditemukan
*/
int binarySearch(int n, int arr[], int target){
    // deklarasi found, left, right
    int found = 0;      // buat flag  (asumsi belum ketemu)
    int left = 0;       // index kiri
    int right = n - 1;  // index kanan
	
    // loop sampai ketemu atau tidak ada elemen lagi
    while(found == 0 && left <= right){
        // cari index tengah
        int mid =  (left + right) / 2;
        // jika mid sesuai target maka ketemu
        if(arr[mid] == target){
            found = mid;
        }
        // jika belum ketemu
        else{
            // jika target lebih kecil dari mid
            if(arr[mid] > target){
                // maka lanjut ke kanan
                left = mid + 1;
            }
            // jika target lebih kecil dari mid
            else{
                // maka lanjut ke kiri
                right = mid - 1;
            }
        }
    }
    // return found (bisa juga return indexnya)
    return found;
}

/*
	prosedur untuk print tampilan
*/
void print(int merge_idx2, bio merge2[], int target, int maksTamp){
	printf("Data Semua Pencari Kerja:\n");
	for(int i = 0; i < merge_idx2; i++){
		printf("%s %s %s %d %d %d quality - %d\n", 
		merge2[i].negara, merge2[i].nama, merge2[i].pend, merge2[i].portoHard, merge2[i].portoSoft, merge2[i].nganggur, merge2[i].quality);
	}
	
	printf("\nData Pencari Kerja Unggulan:\n");
	for(int i = 0; i < maksTamp; i++){
		printf("%s %s %s %d %d %d quality - %d\n", 
		merge2[i].negara, merge2[i].nama, merge2[i].pend, merge2[i].portoHard, merge2[i].portoSoft, merge2[i].nganggur, merge2[i].quality);
	}
	
	printf("\nData Pencarian:\n");
	
	// memindahlan nilai dari struct ke int
	int isi[merge_idx2];
	for(int i = 0; i < merge_idx2; i++){
		isi[i] = merge2[i].quality;
	}
	int found = binarySearch(merge_idx2, isi, target);
    
	if(found > 0){
 		printf("%s %s %s %d %d %d quality - %d\n", 
		merge2[found].negara, merge2[found].nama, merge2[found].pend, merge2[found].portoHard, merge2[found].portoSoft, merge2[found].nganggur, merge2[found].quality);
    }else{
        printf("Tidak Ditemukan\n");
    }
}

/*
	bagian lain yang memanggil perhitungan perhitungan untuk di tampilkan nanti
*/
void sort(int arr1_idx, int arr2_idx, int arr3_idx, bio arr1[], bio arr2[], bio arr3[], char metSort[], int target, int maksTamp){
	// bagian pemilihan sort yang akan digunakan dan juga melakukan sortingannya
	if(strcmp(metSort, "quick") == 0){
		quickSortPivotPinggir(0, arr1_idx - 1, arr1);
		quickSortPivotPinggir(0, arr2_idx - 1, arr2);
		quickSortPivotPinggir(0, arr3_idx - 1, arr3);
		quickSortPivotPinggir(0, arr3_idx - 1, arr3);
	}else{
		selectionSort(arr1_idx, arr1);
		selectionSort(arr2_idx, arr2);
		selectionSort(arr3_idx, arr3);
	}
	
	// bagian menggabungkan pertama untuk arr1 dengan arr2
	int merge_idx1 = arr1_idx + arr2_idx;
	bio merge1[merge_idx1];
	mergeArr(arr1_idx, arr2_idx, arr1, arr2, merge1);

	// bagian menggabungkan kedua untuk gabungan arr1 & arr2 dengan arr3
	int merge_idx2 = merge_idx1 + arr3_idx;
	bio merge2[merge_idx2];
	mergeArr(merge_idx1, arr3_idx, merge1, arr3, merge2);
	
	if(strcmp(metSort, "quick") == 0){
		quickSortPivotPinggir(0, merge_idx2 - 1, merge2); // saya tahu ini salah tapi ini cara ijo yang terpikirkan
	}
	
	// prosedur yang akan memnunculkan output
	print(merge_idx2, merge2, target, maksTamp);
}