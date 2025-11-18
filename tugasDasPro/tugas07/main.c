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
	
	for(int i = 0; i < lowS_idx; i++){
		if(strcmp(lowS[i].cls, "ALEPH") == 0){
			lowS[i].rank = 0;
		}else if(strcmp(upS[i].cls, "WAW") == 0){
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

void tabbleAngela(sum_idx2, mergeFF){
	printf("Abnormalities List:\n");
	
	// menghitung panjang array nama yanhg paling panjang
	int leght_name = strlen(mergeFF[0].name);
	for(int i = 1; i < leght_name; i++){
		if(strlen(mergeFF[i].name > leght_name)){
			leght_name = strlen(mergeFF[i].name);
		}
	}

	// menghitung panjang array id yanhg paling panjang
	int leght_id = strlen(mergeFF[0].id);
	for(int i = 1; i < leght_id; i++){
		if(strlen(mergeFF[i].id > leght_id)){
			leght_name = strlen(mergeFF[i].id);
		}
	}

	// menghitung yang paling banyak digitnya di korban 
	int leght_sacri = 1;
	for(int i = 1; i < leght_name; i++){
		int digit = 0;
		while(mergeFF[i].sacri >= 1){
			mergeFF[i]. sacri % 10;
			digit++
		}
		if(leght_sacri < digit){
			leght_sacri = digit;
		}
	}
}

void angela(int upS_idx, int midS_idx, int lowS_idx, atr upS[], atr midS[], atr lowS[]){
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
	int sum_idx2 = sum_idx1 + lowS_idx;
	atr mergeF[sum_idx1];
	atr mergeFF[sum_idx2];
	printf("ada-%d indeks\n", sum_idx2);
	mergeArr(upS_idx, midS_idx, upS, midS, mergeF);
	mergeArr(sum_idx1, lowS_idx, mergeF, lowS, mergeFF);

	tabbleAngela(sum_idx2, mergeFF);
/*
	for(int i = 0; i < sum_idx2; i++){
		printf("%s %s %d\n", mergeFF[i].name, mergeFF[i].cls, mergeFF[i].sacri);
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
	
	// input banya yang ingin di cari
	int sus_idx;
	scanf("%d", &sus_idx);
	
	// input id yang ingin di cari
	atr sus[sus_idx];
	sus[sus_idx].id[65];
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
	
	
	// bagian void yang digunakan untuk menampilkan permintaan angela
	angela(upS_idx, midS_idx, lowS_idx, upS, midS, lowS);
	return 0;
}