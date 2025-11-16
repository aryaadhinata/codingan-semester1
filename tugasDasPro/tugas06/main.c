/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan tes pemrogaraman
	dalam mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/
#include <stdio.h>
#include <string.h>

void turn(int i, char nama[], int damage, char tipe[], int *Ehp, char Etipe[]){
	if((strcmp(tipe, "Data") == 0) && (strcmp(Etipe, "Vaccine") == 0) ||
		(strcmp(tipe, "Virus") == 0) && (strcmp(Etipe, "Data") == 0) ||
		(strcmp(tipe, "Vaccine") == 0) && (strcmp(Etipe, "Virus") == 0)){
		damage *= 2;
	}
	
	printf("|--- %s memberikan %d damage ke Myostismon\n", nama, damage);
	*Ehp -= damage;
}

void Eturn(int i, char nama[], int *hp, int Edamage,  char tipe[], char Etipe[]){
	if((strcmp(Etipe, "Data") == 0) && (strcmp(tipe, "Vaccine") == 0) ||
		(strcmp(Etipe, "Virus") == 0) && (strcmp(tipe, "Data") == 0) ||
		(strcmp(Etipe, "Vaccine") == 0) && (strcmp(tipe, "Virus") == 0)){
		Edamage *= 2;
	}
	
	printf("/--- %s memberikan %d damage ke Myostismon\n", nama, Edamage);
	*hp -= Edamage;
}

void status(char nama[], int hp){
	if(hp <= 0){
		printf("Sisa HP %s sekarang 0\n", nama);		
	}else{
		printf("Sisa HP %s sekarang %d\n", nama, hp);		
	}
}

void Estatus(int Ehp, int *l){
	if(Ehp <= 0){
		printf("Sisa HP Myostismon sekarang 0\n");
		*l -= 1;
	}else{
		printf("Sisa HP Myostismon sekarang %d\n", Ehp);
	}
}

void pertarungan(int h, int n, int l, char nama[][129], int hp[], int damage[], char tipe[][129], int Ehp, int Edamage, char Etipe[]){
	while((h < n) && (Ehp >= 0)){
		printf("+--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--+\n");
		printf("Saatnya menyerang Kege1apan (> ^ <)\n");
		for(int i = 0; i < 3; i++){
			// prosedur untuk turn kita
			turn(i, nama[i], damage[i], tipe[i], &Ehp, Etipe);
		}

		printf("\nHati - hati, Myostismon akan menyerang (,,>__<,,)\n");
		for(int i = 0; i < 3; i++){
			// prosedur untuk bagian turn musuh
			Eturn(i, nama[i], &hp[i], Edamage, tipe[i], Etipe);
		}
		
		printf("\n");
		for(int i = 0; i < 3; i++){
			// prosedur untuk memperlihatkan status kita
			status(nama[i], hp[i]);
		}
		
		printf("\n");
		// prosedur untuk memperlihatkan status musuh Enemy Status(Estatus)
		Estatus(Ehp, &l);
		h++;
	}
}

void endWorld(int h, int n, int *l, int Ehp, char nama[][129], char Fnama[][129], int hp[], int Fhp[], char rank[][129], char Frank[][129], int damage[], int Fdamage[]){
	printf("+--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--+\n");
	int decide = 3; // penanda kalau semua Hp masih lebih besar dari 0
	for(int i = 0; i < 3; i++){
		if(hp[i] <= 0){
			decide--; 
		}
	}
	
	printf("%d", *l); // bagian ini nilainya nggak sama dengan di bagian prosedur pertarungan
	
	//pengkondisian untuk akhir dunia
	if(Ehp <= 0){
		printf("Yeayy, kita memang anak anak terpilih\n");
	}else if(decide == 0){
		printf("Nooo, dunia akan hancur\n");
	}else if(h == n){
		printf("Siall, Myostismoon Kabur\n");
	}
}


int main(){
	// atribut 
	char nama[3][129], rank[3][129], tipe[3][129];
	int hp[3], damage[3];
	for(int i = 0; i < 3; i++){
		scanf("%s %d %d %s %s", nama[i], &hp[i], &damage[i], rank[i], tipe[i]);
	}
	
	// atribut Myostismon
	int Ehp, Edamage;
	char Etipe[129];
	scanf("%d %d %s", &Ehp, &Edamage, Etipe);
	
	// banyak turn atau giliran
	int n;
	scanf("%d", &n);
	
	// banyak teman
	int m;
	scanf("%d", &m);
	
	char Fnama[m][129], Frank[m][129], Ftipe[m][129];
	int Fhp[m], Fdamage[m];
	for(int i = 0; i < m; i++){
		scanf("%s %d %d %s %s", Fnama[i], &Fhp[i], &Fdamage[i], Frank[i], Ftipe[i]);
	}
	
	// tipe sorting
	char sort[17];
	scanf(" %s", sort);
	
	int h = 0; // menandai banyak turn yang di lakukan
	int l = 1; // menandai apakah ada sisa Enemy HP (Ehp)
	
	//prosedur untuk bagian terjadinya pertarungan
	pertarungan(h, n, l, nama, hp, damage, tipe, Ehp, Edamage, Etipe);

	//prosedur yang menentukan akhir dunia
	endWorld(h, n, &l, Ehp, nama, Fnama, hp, Fhp, rank, Frank, damage, Fdamage);
	return 0;
}