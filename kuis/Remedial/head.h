#include <stdio.h>
#include <string.h>
/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Remedial dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct { // tipe data string yang berisi dua string
    char str1[51], str2[51]; // masing-masing string
} string;

extern int base; // basis pengurutan

int compare(string a, string b); // fungsi untuk membandingkan dua string berdasarkan basis
void swap(string *a, string *b); // fungsi untuk menukar dua string
int partition(string arr[], int low, int high); // fungsi untuk partisi pada quicksort
void quicksort(string arr[], int low, int high); // fungsi quicksort