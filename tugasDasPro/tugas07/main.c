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
	melalkukan sorting tetapi belum selesai!
*/
int quickSortPivotPinggir(int l, int r, atr arr[]){
	int i; int j; char temp[513];
	i = l; j = r;

	do{
		while((arr.rank[i] > arr.rank[r]) && (i <= j)){
			// mencegah i berjalan terlalu jauh melewati batas j
			i = i + 1;
		}
		while((arr.rank[j] > arr.rank[l]) && (i<=j)){
			// mencegah i berjalan terlalu jauh melewati batas i
			j = j - 1;
		}

		if(i < j){
			temp = arr[i].rank;
			arr[i].rank = arr[j].rank;
			arr[j].rank = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i < j);
	
	if(l < j){
		quickSortPivotPinggir(l, j, arr);
	}
	if(i<r){
		quickSortPivotPinggir(i, r, arr);
	}
}

void angela(int upS_idx, int midS_idx, int lowS_idx, atr upS[], atr midS[], atr lowS[]){
	// memanggil void yang akan menandai rank dari setiap entitas
	ranking(upS_idx, midS_idx, lowS_idx, upS, midS, lowS);
	
	quickSortPivotPinggir(0, upS_idx, upS);
	quickSortPivotPinggir(0, midS_idx, midS);
	quickSortPivotPinggir(0, lowS_idx, lowS);
	
	int sum_idx = upS_idx + midS_idx + lowS_idx;
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
	
	// bagian void yang digunakan untuk menampilkan permintaan angela
	angela(upS_idx, midS_idx, lowS_idx, upS, midS, lowS);
	return 0;
}