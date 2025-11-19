#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[65], pend[65], negara[65];
	int portoHard, portoSoft, nganggur, quality; 
}bio;

int kualitas(bio arr);
int quickSortPivotPinggir(int l, int r, bio arr[]);
void selectionSort(int arr_idx, bio arr[]);
void mergeArr(int first, int second, bio satu[], bio dua[], bio arrMerge[]);
int binarySearch(int n, int arr[], int target);
void print(int merge_idx2, bio merge2[], int target, int maksTamp);
void sort(int arr1_idx, int arr2_idx, int arr3_idx, bio arr1[], bio arr2[], bio arr3[], char metSort[], int target, int maksTamp);