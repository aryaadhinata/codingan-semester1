/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan tes pemrogaraman
	dalam mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/
#include <stdio.h>
#include <string.h>

typedef struct{
	char name[257], id[65], cls[65];
	int sacri;
}atr;

int main(){
	// input banyak upper sephirah
	int upS_idx;
	scanf("%d", &upS_idx);
	
	// atribut yang dibawa upper sephirah & loop input
	atr upS[upS_idx];
	upS[upS_idx].name[257], upS[upS_idx].id[65], upS[upS_idx].cls[65], upS[upS_idx].sacri;
	for(int i = 0; i < upS_idx; i++){
		scanf("%s %s %s %d", upS[i].name, upS[i].id, upS[i].cls, &upS[i].sacri);
	}

	// input banyak middle sephirah
	int midS_idx;
	scanf("%d", &midS_idx);
	
	// atribut yang di bawa middle sephirah & loop input
	atr midS[midS_idx];
	midS[midS_idx].name[257], midS[midS_idx].id[65], midS[upS_idx].cls[65], midS[midS_idx].sacri;
	for(int i = 0; i < midS_idx; i++){
		scanf("%s %s %s %d", midS[i].name, midS[i].id, midS[i].cls, &midS[i].sacri);
	}

	// input banyak lower sephirah
	int lowS_idx;
	scanf("%d", &lowS_idx);
	
	// atribut yang dibawa lower sephirah & loop input
	atr lowS[lowS_idx];
	lowS[lowS_idx].name[257], lowS[lowS_idx].id[65], lowS[lowS_idx].cls[65], lowS[lowS_idx].sacri;
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

	return 0;
}