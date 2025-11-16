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

void pertarungan(int *h, int n, int *l, char nama[][129], int hp[], int damage[], char tipe[][129], int Ehp, int Edamage, char Etipe[]){
	while((*h < n) && (Ehp >= 0)){
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
		Estatus(Ehp, l);
		*h++;
	}
}

void endWorld(int *h, int n, int *l, char sort[], int Ehp, char nama[][129], char Fnama[][129], int hp[], int Fhp[], char rank[][129], char Frank[][129], int damage[], int Fdamage[], char tipe[][129], char Ftipe[][129]){
	printf("+--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--++--+--+--+\n");
	int decide = 3; // penanda kalau semua Hp masih lebih besar dari 0
	for(int i = 0; i < 3; i++){
		if(hp[i] <= 0){
			decide--; 
		}
	}
	
	int *Pn = &n;
	printf("%d %d", *h, n);
	printf("\n");
	//pengkondisian untuk akhir dunia
	if(*l <= 0){
		printf("Yeayy, kita memang anak anak terpilih\n");
	}else if(decide == 0){
		printf("Nooo, dunia akan hancur\n");
	}else if(*h == *Pn){
		printf("Siall, Myostismoon Kabur\n");
	}
	
	printf("\n[Kumpulkan semua digimon kalian anak - anak terpilih!!!]\n");
	if(strcmp(sort, "bubble") == 0){
		
	}else if(strcmp(sort, "selection") == 0){
		
	}else if(strcmp(sort, "insertion") == 0){
		
	}else if(strcmp(sort, "quick") == 0){
		
	}
}
