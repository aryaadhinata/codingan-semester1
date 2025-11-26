#include "LCorpIR2.h"

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
/*
	bagian prosedur yang berfungsi untuk menggabungkan dua array
*/
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
	fungsi yang mengcopy cara kerja strlen (kata kang azmi)
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

/*
	bagian void yang mebuat bentuk tabel
*/
void tabble(int sum_idx2, atr mergeFF[]){
	
	// nilai panjang patokan
	int leght_name = 4;
	int leght_id = 3;
	int leght_clas = 13;
	int leght_sacri = 8;
	
	if(sum_idx2 != 0){
		// menghitung panjang array nama yanhg paling panjang
		for(int i = 0; i < sum_idx2; i++){
			if(strlen(mergeFF[i].name) > leght_name){
				leght_name = strlen(mergeFF[i].name);
			}
		}
		
		// menghitung panjang array id yanhg paling panjang
		for(int i = 0; i < sum_idx2; i++){
			if(strlen(mergeFF[i].id) > leght_id){
				leght_id = strlen(mergeFF[i].id);
			}
		}

		// panjang untuk klasifikasinya
		for(int i = 0; i < sum_idx2; i++){
			if(strlen(mergeFF[i].cls) > leght_clas){
				leght_clas = strlen(mergeFF[i].cls);
			}
		}

		// menghitung korban yang paling banyak digitnya
		for(int i = 0; i < sum_idx2; i++){
			if(leght_sacri < (leghtKorban(mergeFF[i].sacri)) + 2){
				leght_sacri = leghtKorban(mergeFF[i].sacri) + 2;		
			}
		//printf("%d --- %d\n", leght_sacri, leghtKorban(mergeFF[i].sacri));
		}
	}	
	
	
	// looping mebuat tabel
	if(sum_idx2 != 0){
		for(int i = 0; i <= sum_idx2 + 3; i++){
			// bagian garis yang ada di atas dan bawah header serta yang ada di bagian paling bawah
			if(i == 0 || i == 2 || i == sum_idx2 + 3){
				printf("*");
				for(int j = 0; j < leght_name + 2; j++){
					printf("-");
				}
				
				printf("*");
				for(int j = 0; j < leght_id + 2; j++){
					printf("-");
				}
				
				printf("*");
				for(int i = 0; i < leght_clas; i++){
					printf("-");
				}

				printf("*");
				for(int j = 0; j < leght_sacri ; j++){
					printf("-");
				}
				
				printf("*");
				printf("\n");
				
			}else if(i == 1){ // bagian yang ada di isi kolom border
				printf("| Nama");
				for(int j = 0; j < leght_name - 3; j++){
					printf(" ");
				}
				
				printf("| ID ");
				for(int j = 0; j < leght_id - 2; j++){
					printf(" ");
				}
				
				printf("| Klasifikasi");
				for(int j = 0; j < leght_clas - 12; j++){
					printf(" ");
				}
				
				printf("| Korban");
				//printf("<%d>", leght_sacri);
				for(int j = 0; j < leght_sacri - 7; j++){
					printf(" ");
				}
				printf("|");
				printf("\n");
			}else{ // bagian utama yang paling penting
				printf("| ");
				printf("%s ", mergeFF[i-3].name);
				if(strlen(mergeFF[i-3].name) < leght_name){
					int sisa = leght_name - strlen(mergeFF[i-3].name);
					for(int j = 0; j < sisa; j++){
						printf(" ");
					}
				}
				
				printf("| ");
				printf("%s ", mergeFF[i-3].id);
				if(strlen(mergeFF[i-3].id) < leght_id){
					int sisa = leght_id - strlen(mergeFF[i-3].id);
					for(int j = 0; j < sisa; j++){
						printf(" ");
					}
				}

				printf("| ");
				printf("%s ", mergeFF[i-3].cls);
				if(strlen(mergeFF[i-3].cls) < leght_clas){
					int sisa = leght_clas - strlen(mergeFF[i-3].cls);
					for(int j = 0; j < sisa - 2; j++){
						printf(" ");
					}
				}
				
				printf("| ");
				//printf("<%d>", leght_sacri);
				printf("%d", mergeFF[i-3].sacri);
				if(leght_sacri > leghtKorban(mergeFF[i-3].sacri)){
					int sisa = leght_sacri - leghtKorban(mergeFF[i-3].sacri);
					//printf(" %d --- %d == %d", leght_sacri, leghtKorban(mergeFF[i-3].sacri), sisa);
					for(int j = 0; j < sisa - 2; j++){
						printf(" ");
					}
				}
				printf(" |\n");
			}
		}
	}else{
		for(int i = 0; i <= 4; i++){
			// bagian garis yang ada di atas dan bawah header serta yang ada di bagian paling bawah
			if(i == 0 || i == 2 || i == 4){
				printf("*");
				for(int j = 0; j < leght_name + 2; j++){
					printf("-");
				}
				
				printf("*");
				for(int j = 0; j < leght_id + 1; j++){
					printf("-");
				}
				
				printf("*");
				for(int i = 0; i < leght_clas; i++){
					printf("-");
				}

				printf("*");
				for(int j = 0; j < leght_sacri; j++){
					printf("-");
				}
				
				printf("*");
				printf("\n");
				
			}else if(i == 1){ // bagian yang ada di isi kolom border
				printf("| Nama");
				for(int j = 0; j < leght_name - 3; j++){
					printf(" ");
				}
				
				printf("| ID");
				for(int j = 0; j < leght_id - 2; j++){
					printf(" ");
				}
				
				printf("| Klasifikasi");
				for(int j = 0; j < leght_clas - 12; j++){
					printf(" ");
				}
				
				printf("| Korban");
				for(int j = 0; j < leght_sacri - 7; j++){
					printf(" ");
				}
				printf("|");
				printf("\n");
			}
		}
	}
}

/*
	sequential untuk mengecek semua id karena idnya kemungkinann besar tidak terurut
*/
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

/*
	prosedur untuk memenuhi permintaan Yesod
*/
void searchYesod(int sum_idx2, atr mergeFF[], int sus_idx, atr sus[]){
	printf("\n//--//--//--//--//--//--//--//--//--//--//--//--//\n");
	printf("Abnormalities Searching:\n");
	printf("------//------//-------//\n");
	
	// pengkondisian
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
	printf("\n//--//--//--//--//--//--//--//--//--//--//--//--//");
}

/*
	sudah bingung unutk decending untuk quick bu rosa jadi pake selction ajalah
*/
void selectionSort(int arr_idx, atr arr[]){
	int i, minIndeks, j;
	atr temp;
	for(i = 0; i < (arr_idx-1); i++){
		/*inisialisasi indeks elemen minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen
		array*/
		for(j= (i + 1); j < arr_idx; j++){
			if((arr[minIndeks].sacri < arr[j].sacri) || ((arr[minIndeks].sacri == arr[j].sacri) && (arr[minIndeks].rank > arr[j].rank)) ||
			((arr[minIndeks].sacri == arr[j].sacri) && (arr[minIndeks].rank == arr[j].rank) && (strcmp(arr[minIndeks].name, arr[j].name) > 0))){
				minIndeks = j;
				}
			}
		//menukar posisi elemen
		temp = arr[i];
		arr[i] = arr[minIndeks];
		arr[minIndeks] = temp;
	}
}

/*
	bagian untuk memenugi permintaan netzach (geram nye)
*/
void netzachSacri(int sum_idx2, atr mergeFF[], int sacri_min){	
	printf("\n");
	atr netks[sum_idx2];
	// memisahkan tipe bentukan karena takut berantem (ada conflict)
	for(int i = 0; i < sum_idx2; i++){
		netks[i] = mergeFF[i];
	}
	selectionSort(sum_idx2, netks);
	
	// menghitung ada berapa banyak nilai yang lebih besar dari nilai minimum
	// nanti abiz plasa dilanjut lagi 
	int netSak[sum_idx2], idx_min = 0;
	for(int i = 0; i < sum_idx2; i++){
		netSak[i] = netks[i].sacri;
		if(netSak[i] >= sacri_min){
			idx_min++;
		}
	}
	printf("Abnormalities List\n");
	tabble(idx_min, netks);
}

/*
	bagian main kedua yang isinya pemanggilan berbagai macam fungsi dan prosedur
*/
void pross(int upS_idx, int midS_idx, int lowS_idx, atr upS[], atr midS[], atr lowS[], int sus_idx, atr sus[], int sacri_min){
	// memanggil void yang akan menandai rank dari setiap entitas
	ranking(upS_idx, midS_idx, lowS_idx, upS, midS, lowS);	
	
	// bagian memanggil prosedur untuk melakukan sorting
	quickSortPivotPinggir(0, upS_idx-1, upS);
	quickSortPivotPinggir(0, midS_idx-1, midS);
	quickSortPivotPinggir(0, lowS_idx-1, lowS);

	
	// bagian untuk merge upper sephiran dengan middle sephirah jadi merge arr
	int sum_idx1 = upS_idx + midS_idx;
	atr mergeF[sum_idx1];
	mergeArr(upS_idx, midS_idx, upS, midS, mergeF);

	// bagian merge kedua untuk ajak join lows sephirah
	int sum_idx2 = sum_idx1 + lowS_idx;
	atr mergeFF[sum_idx2];
	mergeArr(sum_idx1, lowS_idx, mergeF, lowS, mergeFF);
	
	// pemanggilan pemanggilan produr untuk memenuhi berbagai pesanan
	printf("Abnormalities List:\n");
	tabble(sum_idx2, mergeFF);
	printf("-->Sending To Angela\n");
	searchYesod(sum_idx2, mergeFF, sus_idx, sus);
	netzachSacri(sum_idx2, mergeFF, sacri_min);
	printf("-->Sending To Netzach\n");
	
	printf("\n//--//--//--//--//--//--//--//--//--//--//--//--//\n");
	printf("Lobotomy Corporation\n");
	printf("Face the Fear, Build the Future\n");
}
