#include <stdio.h>

int sequentialSearch(int n, int arr[], int target){
    // deklarasi found dan idx
    int found = 0;      // buat flag
    int idx = 0;        // buat index


    // loop sampai ketemu elemen
    while(idx < n && found == 0){
        // jika elemen ketemu maka set found ke 1
        if(arr[idx] == target){
            found = 1;
        }
        // jika tidak maka iterasi index
        else{
            idx++;
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


    int found = sequentialSearch(n, arr, target);
    if(found){
 		printf("Target ketemu\n");
    }else{
        printf("Target tidak ketemu\n");
    }
	
	return 0;
}
