#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Remedial dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    int n1, n2, n3; // jumlah string pada masing-masing tabel
    string str[51]; // array untuk menampung semua string
    int index = 0; // indeks untuk memasukkan string ke dalam array
    
    scanf("%d", &n1); // membaca jumlah string pada tabel pertama
    for(int i = 0; i < n1; i++){ // membaca string pada tabel pertama
        scanf("%s %s", &str[index].str1, &str[index].str2); 
        index++; 
    }

    scanf("%d", &n2); // membaca jumlah string pada tabel kedua
    for(int i = 0; i < n2; i ++){ // membaca string pada tabel kedua
        scanf("%s %s", &str[index].str1, &str[index].str2); 
        index++; 
    }

    scanf("%d", &n3); // membaca jumlah string pada tabel ketiga
    for(int i = 0; i < n3; i ++){ // membaca string pada tabel ketiga
        scanf("%s %s", &str[index].str1, &str[index].str2); 
        index++;
    }

    scanf("%d", &base); // membaca basis pengurutan

    quicksort(str, 0, index - 1); // mengurutkan array string

    for(int i = 0; i < index; i++){ // mencetak string yang sudah diurutkan
        printf("%s %s\n", str[i].str1, str[i].str2); 
    }

    return 0;
}