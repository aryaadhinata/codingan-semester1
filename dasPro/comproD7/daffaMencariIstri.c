#include <stdio.h>
#include <string.h>

int sequentialSearch(int n, char arr[]){
    // deklarasi found dan idx
    int found = 0;      // buat flag
    int idx = 0;        // buat index
	
    // loop sampai ketemu elemen
    while(idx < n && found == 0){
        // jika elemen ketemu maka set found ke 1
        if(arr[idx] >= '0' && arr[idx] <= '9'){
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
	
	char arr[n][129];
	for(int i = 0; i < n; i++){
		scanf("%s", arr[i]);
	}

	printf("\n");
	
	printf("List istri Daffa:\n");
	int found = 0;
	int a = 0;
	char arrAda[n][129]; //array istri
	for(int i = 0; i < n; i++){
		found = sequentialSearch(strlen(arr[i]), arr[i]);
		if(found != 0){
			strcpy(arrAda[a++], arr[i]); // coppy array istri
		}
	}
	
	for(int i = 0; i < a; i++){
		printf("%s\n", arrAda[i]);
	}
	
	printf("\n");
	
    if(a == 1){
 		printf("Horeee, Daffa dapat istri!!\n");
    }else if(a > 1){
		printf("Alamak beliau terdeteksi karbit!\n");
	}else{
        printf("Nooo, Daffa tak dapat istri!!!\n");
    }
	return 0;
}