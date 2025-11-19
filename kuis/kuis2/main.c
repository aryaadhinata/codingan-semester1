/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan tes pemrogaraman
	dalam mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

#include "markse.h"

int main(){
	// bagian untuk menyimoan jenis sort yang ingin digunakan
	char metSort[17];
	scanf("%s", metSort);
	
	// bagian menyimpan nilai input user untuk arr1
	int arr1_idx;
	scanf("%d", &arr1_idx);
	bio arr1[arr1_idx];
	for(int i = 0; i < arr1_idx; i++){
		scanf("%s %s %d %d %d %s", arr1[i].nama, arr1[i].pend, &arr1[i].portoHard, &arr1[i].portoSoft, &arr1[i].nganggur, arr1[i].negara);
		arr1[i].quality = kualitas(arr1[i]); // fungsi untuk menghitung quality
	}
	
	// bagian menyimpan nilai input user untuk arr2
	int arr2_idx;
	scanf("%d", &arr2_idx);
	bio arr2[arr2_idx];
	for(int i = 0; i < arr2_idx; i++){
		scanf("%s %s %d %d %d %s", arr2[i].nama, arr2[i].pend, &arr2[i].portoHard, &arr2[i].portoSoft, &arr2[i].nganggur, arr2[i].negara);
		arr2[i].quality = kualitas(arr2[i]); // fungsi untuk menghitung quality
	}


	// bagian menyimpan nilai input user untuk arr2
	int arr3_idx;
	scanf("%d", &arr3_idx);
	bio arr3[arr3_idx];
	for(int i = 0; i < arr3_idx; i++){
		scanf("%s %s %d %d %d %s", arr3[i].nama, arr3[i].pend, &arr3[i].portoHard, &arr3[i].portoSoft, &arr3[i].nganggur, arr3[i].negara);
		arr3[i].quality = kualitas(arr3[i]); // fungsi untuk menghitung quality
	}
	
	int maksTamp;
	scanf("%d", &maksTamp);
	// bagian untuk meyimpan target quality yang ingin dicari
	int target;
	scanf("%d", &target);
	
	sort(arr1_idx, arr2_idx, arr3_idx, arr1, arr2, arr3, metSort, target, maksTamp);
	return 0;
} 