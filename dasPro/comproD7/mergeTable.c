#include <stdio.h>

void mergeArr(int n, int arr1[], int n2, int arr2[], int arr3[]){
    int idx3 = 0;
    
	for(int i = 0; i < n; i++){
        arr3[idx3] = arr1[i];
        idx3++;
    }
    for(int i = 0; i < n; i++){
        arr3[idx3] = arr2[i];
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
    


    int arr3[n + n2];
    mergeArr(n, arr1, n2, arr2, arr3);


    for(int i = 0; i < n + n2; i++){
        printf("%d ", arr3[i]);
    }
    printf("\n");

	return 0;
}