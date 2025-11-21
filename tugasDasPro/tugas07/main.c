/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan tes pemrogaraman
	dalam mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/
#include <stdio.h>
#include <string.h>

typedef struct{ // struct yang akan digunakan dalam program
	char name[257], id[65], cls[65];
	int sacri, rank;
}atr;

/*
	bagian ini untuk mennadai rankingnya agar nanti  ketika yang di compare
	lebih mudah.
*/
void ranking(int upS_idx, int midS_idx, int lowS_idx, atr upS[], atr midS[], atr lowS[]){
	//melakukan loop untuk  bagian upS
	for(int i = 0; i < upS_idx; i++){
		if(strcmp(upS[i].cls, "ALEPH") == 0){
			upS[i].rank = 0;
		}else if(strcmp(upS[i].cls, "WAW") == 0){
			upS[i].rank = 1;
		}else if(strcmp(upS[i].cls, "HE") == 0){
			upS[i].rank = 2;
		}else if(strcmp(upS[i].cls, "TETH") == 0){
			upS[i].rank = 3;
		}else if(strcmp(upS[i].cls, "ZAYIN") == 0){
			upS[i].rank = 4;
		}
	}
	
	//melakukan loop untuk  bagian upS
	for(int i = 0; i < midS_idx; i++){
		if(strcmp(midS[i].cls, "ALEPH") == 0){
			midS[i].rank = 0;
		}else if(strcmp(midS[i].cls, "WAW") == 0){
			midS[i].rank = 1;
		}else if(strcmp(midS[i].cls, "HE") == 0){
			midS[i].rank = 2;
		}else if(strcmp(midS[i].cls, "TETH") == 0){
			midS[i].rank = 3;
		}else if(strcmp(midS[i].cls, "ZAYIN") == 0){
			midS[i].rank = 4;
		}
	}
	
	//melakukan loop untuk  bagian lowers
	for(int i = 0; i < lowS_idx; i++){
		if(strcmp(lowS[i].cls, "ALEPH") == 0){
			lowS[i].rank = 0;
		}else if(strcmp(lowS[i].cls, "WAW") == 0){
			lowS[i].rank = 1;
		}else if(strcmp(lowS[i].cls, "HE") == 0){
			lowS[i].rank = 2;
		}else if(strcmp(lowS[i].cls, "TETH") == 0){
			lowS[i].rank = 3;
		}else if(strcmp(lowS[i].cls, "ZAYIN") == 0){
			lowS[i].rank = 4;
		}
	}
}

/*
	melalkukan sorting dengan menggunakan quick sort pivot pinggir
*/
int quickSortPivotPinggir(int l, int r, atr arr[]){
	int i; int j; atr temp;
	i = l; j = r;

	do{
		/*
			pengkondisian untukk bagian pengurutan untuk i
		*/
		while((arr[i].rank < arr[r].rank || (arr[i].rank == arr[r].rank && arr[i].sacri > arr[r].sacri) ||
		arr[i].rank == arr[r].rank && arr[i].sacri == arr[r].sacri && strcmp(arr[i].name, arr[r].name) < 0 ) 
		&& (i <= j)){
			// mencegah i berjalan terlalu jauh melewati batas j
			i = i + 1;
		}
		
		/*
			pengkondisian untukk bagian pengurutan untuk j
		*/
		while((arr[j].rank > arr[l].rank || (arr[j].rank == arr[l].rank && arr[j].sacri < arr[l].sacri) ||
		arr[j].rank == arr[l].rank && arr[j].sacri == arr[l].sacri && strcmp(arr[j].name, arr[l].name) > 0) 
		&& (i <= j)){
			// mencegah i berjalan terlalu jauh melewati batas i
			j = j - 1;
		}

		/*
			bagian penukaran
		*/
		if(i < j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i < j);
	
	/*
		bagian untuk merekursif
	*/
	if(l < j){
		quickSortPivotPinggir(l, j, arr);
	}
	if(i < r){
		quickSortPivotPinggir(i, r, arr);
	}
}

void mergeArr(int first, int second, atr satu[], atr dua[], atr arrMerge[]){
	// deklarasi dan inisialisasi index untuk ketiga array
    int idx1 = 0, idx2 = 0, idx3 = 0;
    // loop sampai arr1 atau arr2 habis (salah satunya dulu)
    while(idx1 < first && idx2 < second){
        // jika elemen arr1 lebih kecil dari arr2
        if((satu[idx1].rank < dua[idx2].rank) || ((satu[idx1].rank == dua[idx2].rank) && (satu[idx1].sacri > dua[idx2].sacri)) ||
		((satu[idx1].rank == dua[idx2].rank) && (satu[idx1].sacri == dua[idx2].sacri) && (strcmp(satu[idx1].name, dua[idx2].name) < 0))){
            // masukan elemen tersebut ke arr3
            arrMerge[idx3] = satu[idx1];
            idx1++;
        }else{
        // jika elemen arr2 lebih kecil dari arrar
            // masukan elemen tersebut ke arr3
            arrMerge[idx3] = dua[idx2];
            idx2++;
        }
        // iterasi untuk index arr3
        idx3++;
    }


    // jika ada sisa di arr1, maka masukan ke arr3
    while(idx1 < first){
        arrMerge[idx3] = satu[idx1];
        idx1++;
        idx3++;
    }
    // jika ada sisa di arr2, maka masukan ke arr3
    while(idx2 < second){
        arrMerge[idx3] = dua[idx2];
        idx2++;
        idx3++;
    }
}
/*
	prosedur untuk menampilkan apa yang diingan angela
*/

int leghtKorban(int n){
	if(n == 0){
		return 1;
	}else{
		int count = 0;
		while(n != 0){
			n /= 10;
			count++;
		}
		return count;
	}
}

void tabbleAngela(int sum_idx2, atr mergeFF[]){
	printf("Abnormalities List:\n");
	
	// menghitung panjang array nama yanhg paling panjang
	int leght_name = 5;
	for(int i = 0; i < sum_idx2; i++){
		if(strlen(mergeFF[i].name) > leght_name){
			leght_name = strlen(mergeFF[i].name);
		}
	}

	// menghitung panjang array id yanhg paling panjang
	int leght_id = 8;
	for(int i = 0; i < sum_idx2; i++){
		if(strlen(mergeFF[i].id) > leght_id){
			leght_name = strlen(mergeFF[i].id);
		}
	}
	
	// panjang untuk klasifikasinya
	int leght_clas = strlen("klasifikasi");
	for(int i = 0; i < sum_idx2; i++){
		if(strlen(mergeFF[i].cls) > leght_clas){
			leght_clas = strlen(mergeFF[i].cls);
		}
	}
	
	// menghitung korban yang paling banyak digitnya
	int leght_sacri = 7;
	for(int i = 0; i < sum_idx2; i++){
		if(leght_sacri < leghtKorban(mergeFF[i].sacri)){
			leght_sacri = leghtKorban(mergeFF[i].sacri);		
		}
	}
	
	// printf("%d %d %d\n", leght_name, leght_id, leght_sacri);
	for(int i = 0; i <= sum_idx2 + 3; i++){
		if(i == 0 || i == 2 || i == sum_idx2 + 3){
			printf("*");
			for(int j = 0; j < leght_name + 2; j++){
				printf("-");
			}
			
			printf("*");
			for(int j = 0; j < leght_id + 1; j++){
				printf("-");
			}
			
			printf("*");
			for(int i = 0; i < leght_clas + 2; i++){
				printf("-");
			}

			printf("*");
			for(int j = 0; j < leght_sacri + 2; j++){
				printf("-");
			}
			
			printf("*");
			printf("\n");
			
		}else if(i == 1){
			printf("| Nama");
			for(int j = 0; j < leght_name - 3; j++){
				printf(" ");
			}
			
			printf("| ID");
			for(int j = 0; j < leght_id - 2; j++){
				printf(" ");
			}
			
			printf("| Klasifikasi");
			for(int j = 0; j < leght_clas - 10; j++){
				printf(" ");
			}
			
			printf("| Korban");
			for(int j = 0; j < leght_sacri - 5; j++){
				printf(" ");
			}
			printf("|");
			printf("\n");
		}else{
			printf("| %s ", mergeFF[i-3].name);
			if(strlen(mergeFF[i-3].name) < leght_name){
				int sisa = leght_name - strlen(mergeFF[i-3].name);
				for(int j = 0; j < sisa; j++){
					printf(" ");
				}
			}

			printf("| %s", mergeFF[i-3].id);
			if(strlen(mergeFF[i-3].id) < leght_id){
				int sisa = leght_id - strlen(mergeFF[i-3].id);
				for(int j = 0; j < sisa; j++){
					printf(" ");
				}
			}

			printf("| %s ", mergeFF[i-3].cls);
			if(strlen(mergeFF[i-3].cls) < leght_clas){
				int sisa = leght_clas - strlen(mergeFF[i-3].cls);
				for(int j = 0; j < sisa; j++){
					printf(" ");
				}
			}
			
			printf("| %d", mergeFF[i-3].sacri);
			if(leght_sacri > leghtKorban(mergeFF[i-3].sacri)){
				int sisa = leght_sacri - leghtKorban(mergeFF[i-3].sacri);
				for(int j = 0; j < sisa; j++){
					printf(" ");
				}
			}
			printf(" |\n");
		}
	}
	printf("-->Sending To Angela\n");
}

int sequentialSearch(int i, int sus_idx, atr mergeFF[], atr sus[]){
    // deklarasi found dan idx
    int found = -1;      // buat flag
    int idx = 0;        // buat index


    // loop sampai ketemu elemen
    while(idx <= sus_idx && found == -1){
        // jika elemen ketemu maka set found ke 1
        if(strcmp(mergeFF[idx].id, sus[i].id) == 0){
            found = idx;
        }
        // jika tidak maka iterasi index
        else{
            idx++;
        }
    }
    // return found (bisa juga return indexnya)
    return found;
}

void searchYesod(int sum_idx2, atr mergeFF[], int sus_idx, atr sus[]){
	printf("\n//--//--//--//--//--//--//--//--//--//--//--//--//\n");
	printf("Abnormalities Searching:\n");
	printf("------//------//-------//\n");
	
	for(int i = 0; i < sus_idx; i++){
		int found = sequentialSearch(i , sum_idx2, mergeFF, sus);
		if(found >= 0 ){
			printf("Abnormality Found!!!\n");
			printf("Name: %s\n", mergeFF[found].name);
			printf("ID: %s\n", mergeFF[found].id);
			printf("Classification: %s\n", mergeFF[found].cls);
			printf("Casualties: %d\n", mergeFF[found].sacri);
		}else{
			printf("Abnormality %s not found!!\n", sus[i].id);
			printf("Maybe it will be send some other day.\n");
		}
		printf("------//------//-------//\n");
	}
	printf("-->Sending To Yesod\n");
	
}

void netzachSacri(int sum_idx2, atr mergeFF, int sacri_min){
	int maks = 0;
	for(int i = 0; i < sum_idx2; i++){
		if(maks < mergeFF[i].sacri){
			maks = mergeFF[i].sacri;
		}
	}
}

void pross(int upS_idx, int midS_idx, int lowS_idx, atr upS[], atr midS[], atr lowS[], int sus_idx, atr sus[], int sacri_min){
	// memanggil void yang akan menandai rank dari setiap entitas
	ranking(upS_idx, midS_idx, lowS_idx, upS, midS, lowS);
/*
	for(int i = 0; i < upS_idx; i++){
		printf("%s %s\n", upS[i].name, upS[i].cls);
	}
	for(int i = 0; i < midS_idx; i++){
		printf("%s %s\n", midS[i].name, midS[i].cls);
	}
	for(int i = 0; i < lowS_idx; i++){
		printf("%s %s\n", lowS[i].name, lowS[i].cls);
	}
	int sum_idx = upS_idx + midS_idx + lowS_idx;
*/	
	
	// bagian memanggil prosedur untuk melakukan sorting
	quickSortPivotPinggir(0, upS_idx-1, upS);
	quickSortPivotPinggir(0, midS_idx-1, midS);
	quickSortPivotPinggir(0, lowS_idx-1, lowS);

	
	// disini ada bagiann salah aku rasa kayak kurang sesuatu jadi yang terakhir nggak di bandingin
	int sum_idx1 = upS_idx + midS_idx;
	atr mergeF[sum_idx1];
	mergeArr(upS_idx, midS_idx, upS, midS, mergeF);
	
	int sum_idx2 = sum_idx1 + lowS_idx;
	atr mergeFF[sum_idx2];
	mergeArr(sum_idx1, lowS_idx, mergeF, lowS, mergeFF);

	tabbleAngela(sum_idx2, mergeFF);
	searchYesod(sum_idx2, mergeFF, sus_idx, sus);
	printf("\n");
	netzachSacri(sum_idx2, mergeFF, sacri_min);
	
	/*
	for(int i = 0; i < sus_idx; i++){
		printf("%s \n", sus[i].id);
	}
	*/
}

int main(){
	// input banyak upper sephirah
	int upS_idx;
	scanf("%d", &upS_idx);
	
	// atribut yang dibawa upper sephirah & loop input
	atr upS[upS_idx];
	for(int i = 0; i < upS_idx; i++){
		scanf("%s %s %s %d", upS[i].name, upS[i].id, upS[i].cls, &upS[i].sacri);
	}

	// input banyak middle sephirah
	int midS_idx;
	scanf("%d", &midS_idx);
	
	// atribut yang di bawa middle sephirah & loop input
	atr midS[midS_idx];
	for(int i = 0; i < midS_idx; i++){
		scanf("%s %s %s %d", midS[i].name, midS[i].id, midS[i].cls, &midS[i].sacri);
	}

	// input banyak lower sephirah
	int lowS_idx;
	scanf("%d", &lowS_idx);
	
	// atribut yang dibawa lower sephirah & loop input
	atr lowS[lowS_idx];
	for(int i = 0; i < lowS_idx; i++){
		scanf("%s %s %s %d", lowS[i].name, lowS[i].id, lowS[i].cls, &lowS[i].sacri);
	}
	
	// input banyak yang ingin di cari
	int sus_idx;
	scanf("%d", &sus_idx);
	
	// input id yang ingin di cari
	atr sus[sus_idx];
	sus[sus_idx];
	for(int i = 0; i < sus_idx; i++){
		scanf("%s", sus[i].id);
	}

	// input nilai miminimal korban yang ingin di tampilkan
	int sacri_min;
	scanf("%d", &sacri_min);
/*
	for(int i = 0; i < upS_idx; i++){
		printf("%s %s\n", upS[i].name, upS[i].cls);
	}
	for(int i = 0; i < midS_idx; i++){
		printf("%s %s\n", midS[i].name, midS[i].cls);
	}
	for(int i = 0; i < lowS_idx; i++){
		printf("%s %s\n", lowS[i].name, lowS[i].cls);
	}
	int sum_idx = upS_idx + midS_idx + lowS_idx;
*/	
	
	
	// bagian void yang digunakan untuk melakukan proses
	pross(upS_idx, midS_idx, lowS_idx, upS, midS, lowS, sus_idx, sus, sacri_min);
	return 0;
}