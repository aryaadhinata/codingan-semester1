/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan tes pemrogaraman
	dalam mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/
#include <stdio.h>
#include <string.h>

typedef struct{
	char name[], id[], cls[];
	int sacri[];
}atr;

void anggela(int upS, int midS, int lowS,
	char name_upS[][257], char name_midS[][257], char name_lowS[][257],
	char id_upS[][65], char id_midS[][65], char id_lowS[][65],
	char cls_upS[][65], char cls_midS[][65], char cls_lowS[][65], 
	int sacri_upS[], int sacri_midS[], int sacri_lowS[]){
	
	printf("Abnormalities List:");

}

int main(){
	// input banyak upper sephirah
	int upS;
	scanf("%d", &upS);
	
	// atribut yang dibawa upper sephirah & loop input
	/*
	char name_upS[upS][257], id_upS[upS][65], cls_upS[upS][65];
	int sacri_upS[upS];
	*/
	atr upS[];
	upS[].name[], upS[].id[], upS[].cls[], ups[].sacri;
	for(int i = 0; i < upS; i++){
		scanf("%s %s %s %d", name_upS[i], id_upS[i], cls_upS[i], &sacri_upS[i]);
	}

	// input middle sephirah
	int midS;
	scanf("%d", &midS);
	
	// atribut yang di bawa middle sephirah & loop input
	char name_midS[midS][257], id_midS[midS][65], cls_midS[midS][65];
	int sacri_midS[midS];
	for(int i = 0; i < midS; i++){
		scanf("%s %s %s %d", name_midS[i], id_midS[i], cls_midS[i], &sacri_midS[i]);
	}

	// input lower sephirah
	int lowS;
	scanf("%d", &lowS);
	
	// atribut yang dibawa lower sephirah & loop input
	char name_lowS[lowS][257], id_lowS[lowS][65], cls_lowS[lowS][65];
	int sacri_lowS[lowS];
	for(int i = 0; i < lowS; i++){
		scanf("%s %s %s %d", name_lowS[i], id_lowS[i], cls_lowS[i], &sacri_lowS[i]);
	}
	
	// input banya yang inin di cari
	int sus;
	scanf("%d", &sus);
	
	// input id yang ingin di cari
	char id_sus[sus][65];
	for(int i = 0; i < sus; i++){
		scanf("%s", id_sus[i]);
	}

	// input nilai miminimal korban yang ingin di tampilkan
	int sacri;
	scanf("%d", &sacri);

	anggela(upS, midS, lowS, name_upS, name_midS, name_lowS,
			id_upS, id_midS, id_lowS, cls_upS, cls_midS, cls_lowS, 
			sacri_upS, sacri_midS, sacri_lowS);
	return 0;
}