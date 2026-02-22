#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Remedial dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int base; // basis pengurutan

int compare(string a, string b){ // fungsi untuk membandingkan dua string berdasarkan basis
    if(base == 1){ // membandingkan berdasarkan str1
        return strcmp(a.str1, b.str1) > 0; // mengembalikan true jika a > b
    }else{
        return strcmp(a.str2, b.str2) > 0; // membandingkan berdasarkan str2
    }
}

void swap(string *a, string *b){ // fungsi untuk menukar dua string 
    string temp = *a; 
    *a = *b; 
    *b = temp;
}

int partition(string arr[], int low, int high){ // fungsi untuk partisi pada quicksort
    string pivot = arr[high]; // memilih pivot
    int i = (low - 1); // indeks elemen terkecil

    for(int j = low; j <= high - 1; j++){ // mengiterasi elemen
        if(compare(arr[j], pivot)){ // membandingkan elemen dengan pivot
            i++;
            swap(&arr[i], &arr[j]); // menukar elemen jika lebih kecil dari pivot
        }
    }

    swap(&arr[i + 1], &arr[high]); // menukar pivot ke posisi yang benar
    return (i + 1); // mengembalikan indeks pivot
}

void quicksort(string arr[], int low, int high){ // fungsi quicksort
    if(low < high){ // kondisi dasar 
        int part = partition(arr, low, high); // melakukan partisi

        quicksort(arr, low, part - 1); // mengurutkan bagian kiri
        quicksort(arr, part + 1, high); // mengurutkan bagian kanan
    }
}