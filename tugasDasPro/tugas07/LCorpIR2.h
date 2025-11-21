#include <stdio.h>
#include <string.h>

typedef struct{ // struct yang akan digunakan dalam program
	char name[257], id[65], cls[65];
	int sacri, rank;
}atr;
void ranking(int upS_idx, int midS_idx, int lowS_idx, atr upS[], atr midS[], atr lowS[]);
int quickSortPivotPinggir(int l, int r, atr arr[]);
void mergeArr(int first, int second, atr satu[], atr dua[], atr arrMerge[]);
int leghtKorban(int n);
void tabble(int sum_idx2, atr mergeFF[]);
int sequentialSearch(int i, int sus_idx, atr mergeFF[], atr sus[]);
void searchYesod(int sum_idx2, atr mergeFF[], int sus_idx, atr sus[]);
void selectionSort(int arr_idx, atr arr[]);
void netzachSacri(int sum_idx2, atr mergeFF[], int sacri_min);
void pross(int upS_idx, int midS_idx, int lowS_idx, atr upS[], atr midS[], atr lowS[], int sus_idx, atr sus[], int sacri_min);
