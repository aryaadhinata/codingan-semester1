#include <stdio.h>
#include <string.h>

void pertarungan(int n, char nama[][129], int hp[], int damage[], char rank[][129], char tipe[][129], int Ehp, int Edamage, char Etipe[]){
	for(int h = 0; h < n; h++){
		printf("+--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--+\n");
		printf("Saatnya menyerang Kege1apan (> ^ <)\n");
		for(int i = 0; i < 3; i++){
			turn(nama[i], hp[i], damage[i], rank[i], tipe[i], Ehp, Edamage, Etipe);
		}
		printf("Hati - hati, Myostismon akan menyerang (,,>__<,,)\n");
	}
}

void turn(char nama[], int hp, int damage, char rank[], char tipe[], int Ehp, int Edamage, char Etipe[]){
	if((strcmp(tipe, "Data") == 0) && (strcmp(Etipe, "Vaccine") == 0) ||
		(strcmp(tipe, "Virus") == 0) && (strcmp(Etipe, "Data") == 0) ||
		(strcmp(tipe, "Vaccine") == 0) && (strcmp(Etipe, "Virus") == 0)){
		damage *= 2;
	}
	
	printf("|--- %s memberikan %d damage ke Myostismon\n", nama, damage);
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
	
	pertarungan(n, nama, hp, damage, rank, tipe, Ehp, Edamage, Etipe);
	return 0;
}