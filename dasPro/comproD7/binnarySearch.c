#include <stdio.h>

int binarySearch(int n, int arr[], int target){
    // deklarasi found, left, right
    int found = 0;      // buat flag  (asumsi belum ketemu)
    int left = 0;       // index kiri
    int right = n - 1;  // index kanan


    // loop sampai ketemu atau tidak ada elemen lagi
    while(found == 0 && left <= right){
        // cari index tengah
        int mid = (left + right) / 2;
        // jika mid sesuai target maka ketmeu
        if(arr[mid] == target){
            found = 1;
        }
        // jika belum ketemu
        else{
            // jika target lebih besar dari mid
            if(arr[mid] < target){
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


int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
   
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    int target;
    scanf("%d", &target);


    int found = binarySearch(n, arr, target);
    if(found){
 		printf("Target ketemu\n");
    }else{
        printf("Target tidak ketemu\n");
    }
	
	return 0;
}
