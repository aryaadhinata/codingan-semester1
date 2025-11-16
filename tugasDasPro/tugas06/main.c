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
			turn(i, nama[i], damage[i], tipe[i], &Ehp, Etipe);
		}

		printf("\nHati - hati, Myostismon akan menyerang (,,>__<,,)\n");
		for(int i = 0; i < 3; i++){
			Eturn(i, nama[i], &hp[i], Edamage, tipe[i], Etipe);
		}
		
		printf("\n");
		for(int i = 0; i < 3; i++){
			status(nama[i], hp[i]);
		}
		
		printf("\n");
		Estatus(Ehp, &l);
		h++;
	}
}

void endWorld(int h, int n, int *l, int Ehp, char nama[][129], char Fnama[][129], int hp[], int Fhp[], char rank[][129], char Frank[][129], int damage[], int Fdamage[]){
	printf("+--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--+\n");
	int decide = 3;
	for(int i = 0; i < 3; i++){
		if(hp[i] <= 0){
			decide--; 
		}
	}
	
	printf("%d", l);
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
	
	int h = 0;
	int l = 1;
	pertarungan(h, n, l, nama, hp, damage, tipe, Ehp, Edamage, Etipe);

	endWorld(h, n, &l, Ehp, nama, Fnama, hp, Fhp, rank, Frank, damage, Fdamage);
	return 0;
}