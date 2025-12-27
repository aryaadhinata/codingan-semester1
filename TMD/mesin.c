#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/
//File Kosong

int indeks;
int panjangKata;
char cw[129];

void Salam(){
printf("- _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -\n");
printf("+      /|_/|                                                +\n");
printf("+     ( O.O )              !!!Selamat Datang!!!             +\n");
printf("+      > ^ <                                                +\n");
printf("- _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -\n");
printf("\n\n");
}

void MENU(){
    printf("=========================================================================\n");
    printf("|                         < Daftar Perintah >                           |\n");
    printf("|   1. INSERT                                                           |\n");
    printf("|   (langsung masukan nilai key, content, [skill, note dan scorenya])   |\n");
    printf("|   2. UPDATE                                                           |\n");
    printf("|   (langsung masukan nilai key, content, [skill, note dan scorenya])   |\n");
    printf("|   3. DELETE                                                           |\n");
    printf("|   (langsung masukan nilai fkeynya saja)                               |\n");
    printf("|   4. SELECT                                                           |\n");
    printf("|   (Sebut nama filenya saja)                                           |\n");
    printf("=========================================================================\n");
    printf("    [skil, ote dan score di gunakan ketika membuka file TabelPrimary] \n\n");
}

void LIST(){
    printf("=====================================================\n");
    printf("|                     Daftar File                   |\n");
    printf("|   1. TableComplete.txt (Hanya bisa dilihat)       |\n");
    printf("|   2. TabelPrimary.txt                             |\n");
    printf("|   3. SkillTable.txt                               |\n");
    printf("|   4. NoteTable.txt                                |\n");
    printf("=====================================================\n");
}

void STARTWORD(char pita[]){
    indeks = 0;
    panjangKata = 0;
    while(pita[indeks] == ' '){
        indeks++;
    }

    while((pita[indeks] != ' ') && (pita[indeks] != '#')){
        cw[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }
    
    cw[panjangKata] = '\0';
}

void RESETWORD(){
    panjangKata = 0;
    cw[panjangKata] = '\0';
}


void INCWORD(char pita[]){
    panjangKata = 0;
    while(pita[indeks] == ' '){
        indeks++;
    }
    
    while((pita[indeks] != ' ') && (pita[indeks] != '#')){
        cw[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }
    
    cw[panjangKata] = '\0';
}

char* GETWORD(){
    return cw;
}

int GETPANJANGKATA(){
    return panjangKata;
}

int EOPWORD(char pita[]){
    if(pita[indeks] == '#'){
        return 1;
    }else{
        return 0;
    }
}

void mReadFile(int *a, int *aP, atr obj[]){ // membaca file utama
    FILE *ftemp;
    ftemp = fopen("TabelPrimary.txt", "r");

    if(ftemp == NULL){
        printf("File tidak ada\n");
    }else{
        int rval = fscanf(ftemp, "%s %s %s %s %s\n",
            obj[*a].fkey, obj[*a].cont, obj[*a].kskill,
            obj[*a].knote, obj[*a].score);

        if(rval == EOF){
            printf("File kosong\n");
        }else{
            while(strcmp(obj[*a].fkey, "####") != 0){
                *a = *a + 1;

                fscanf(ftemp, "%s %s %s %s %s\n",
                    obj[*a].fkey, obj[*a].cont,
                    obj[*a].kskill,obj[*a].knote, obj[*a].score);
            }
        }
        *aP = *a;
        fclose(ftemp);
    }
}


void readFile(int *a, int *b, int *tF, atr obj[], char fileName[]){ // membaca file sampingan
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    if(*a != 0){ // memulai indeks dari 0 lagi
        *a = 0;
    }

    int rval = fscanf(ftemp, "%s %s\n", obj[*a].skey, obj[*a].sname);
    if((strcmp(obj[*a].skey, "####") == 0) || rval == EOF){ // menghindari file kosong
        printf("File Kosong\n");
    }else{
        while(strcmp(obj[*a].skey, "####") != 0){
            *a = *a +1;
            fscanf(ftemp, "%s %s", obj[*a].skey, obj[*a].sname); // membaca isi file
        }
    }

    *b = *a; // memindahakan nilai banyak data dalam file ini
    *tF = (*tF % 2) + 1; // menandai pebacaan keberapa
    fclose(ftemp);
}

void mMerge(int *aP, int *aS, int *aN, int *tF, atr obj[], char fileName[]){ // mengabungkan file
    FILE *fcFile;
    FILE *fPTable;
    FILE *fSkill;
    FILE *fNote;

    fcFile = fopen(fileName, "w");
    fPTable = fopen("TabelPrimary.txt", "r");
    fSkill = fopen("SkillTable.txt", "r");
    fNote = fopen("NoteTable.txt", "r");

    for(int i = 0; i < *aP; i++){
        fscanf(fPTable, "%s %s %s %s %s\n", obj[i].fkey, obj[i].cont, 
                obj[i].kskill, obj[i].knote,&obj[i].score); // membaca file utama
        
        switch (*tF){ // kondisi untuk melakukan pergantian skey dengan namanya
            case 1:{ // case file SkillTable.txt
                for(int j = 0; j < *aS; j++){
                    if(strcmp(obj[j].skey, obj[i].kskill) == 0){
                        strcpy(obj[i].sskill, obj[j].sname);
                    }
                }
                break;
            }case 2:{ // case file NoteTable.txt
                for(int j = 0; j < *aN; j++){
                    if(strcmp(obj[j].skey, obj[i].knote) == 0){
                        strcpy(obj[i].snote, obj[j].sname);
                    }
                }
                break;
            }
        }
        fprintf(fcFile, "%s %s %s %s %s\n", obj[i].fkey, obj[i].cont,
                obj[i].sskill, obj[i].snote, obj[i].score); // digabungkan ke FighterComplete.txt
    }
    
    fprintf(fcFile, "%s %s %s %s %s\n", "####", "####", "####", "####", -999); // dummy or EOF

    fclose(fcFile);
    fclose(fPTable);
    fclose(fSkill);
    fclose(fNote);
}

void refresh(){ // digunakan untuk memperbaharui data
    int a = 0, aP = 0, aS = 0, 
        aN = 0, tfKey = 0;
    atr comp[65];

    mReadFile(&a, &aP, comp);

    readFile(&a, &aS, &tfKey, comp, "SkillTable.txt");
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt");

    readFile(&a, &aN, &tfKey, comp, "NoteTable.txt");
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt");
}

void INSm(int n, atr obj[], atr new){ // insert untuk file utama
    atr temp[65];
    int a = 0;

    FILE *ftemp;
    ftemp = fopen("TabelPrimary.txt", "r");
    while(strcmp(obj[a].fkey, "####") != 0){
        fscanf(ftemp, "%s %s %s %s %s\n",
            obj[a].fkey, obj[a].cont,
            obj[a].kskill,obj[a].knote,&obj[a].score);
        a++;
    }

    a = 0;
    do{
        temp[a] = obj[a]; // memasukan nilai obj ke temp, temp yang akan kita otak atik
        a++;
    }while(strcmp(obj[a].fkey, "####") != 0);
    
    fclose(ftemp);

    int mark = 1;
    for(int i = 0; i < a; i++){
        if(strcmp(temp[i].fkey, new.fkey) == 0){
            mark = 0;
        }
    }

    if(mark == 1){    
        if(strcmp(new.fkey, temp[0].fkey) < 0){ // jika urutan fkey di paling atas
            for(int i = n-1; i >= 0; i--) {
                temp[i+1] = temp[i]; // memundurkan semua data
            }
            a++;
            temp[0] = new;
        }else if(strcmp(new.fkey, temp[a-1].fkey) > 0){ // jika urutan fkey di paling bawah
            temp[a] = new; // langsung tambah di akhir
            a++;
        }else{ // jika urutan fkey di tengah tengah
            int k = 0, stop = 0;
            while((k < a) && (stop == 0)){ // mencari posisi fkey baru
                if(strcmp(temp[k].fkey, new.fkey) > 0){
                    stop = 1;
                }else{
                    k++;
                }
            }

            for(int l = a-1; l >= k; l--) { // mengegeser data lama
                temp[l+1] = temp[l];
            }
            temp[k] = new; // memasukan new ke temp
        }

        ftemp = fopen("TabelPrimary.txt", "w");
        for(int i = 0; i < a; i++) { // flush semua data
            fprintf(ftemp, "%s %s %s %s %s\n", temp[i].fkey, temp[i].cont, 
                    temp[i].kskill, temp[i].knote,temp[i].score);
        }
        fprintf(ftemp, "%s %s %s %s %s\n", "####", "####", "####", "####", -999);
        fclose(ftemp);
        printf("Data berhasil ditambahkan\n");
    }else{
        printf("fkey %s sudah ada\n", new.fkey);
    }
}

void INS(int n, atr obj[], atr new, char fileName[]){ // insert untuk file sampingan
    atr temp[65];
    
    FILE *ftemp;
    ftemp = fopen(fileName, "r");
    for(int i = 0; i < n; i++) { // membaca isi data didalam file
        fscanf(ftemp, "%s %s\n", obj[i].skey, obj[i].sname);
    }

    int a = 0;
    do{
        temp[a] = obj[a]; // memasukan data obj ke temp, temp yang kita otak atik
        a++;
    }while(strcmp(obj[a].skey, "####") != 0);
    
    fclose(ftemp);

    int mark = 1;
    for(int i = 0; i < a; i++){
        if(strcmp(temp[i].skey, new.skey) == 0){
            mark = 0;
        }
    }

    if(mark == 1){
        if(strcmp(new.skey, temp[0].skey) < 0){ // jika urutan skey paling atas
            for(int i = n-1; i >= 0; i--) {
                temp[i+1] = temp[i]; // memundurkan semua data
            }
            a++;
            temp[0] = new;
        }else if(strcmp(new.skey, temp[a-1].skey) > 0){ // jika urutan skey paling bawah
            temp[a] = new; // langsung tambah di akhir
            a++;
        }else{ // jika urutan skey di tengah tengah
            int k = 0, stop = 0;
            while((k < a) && (stop == 0)){ // mencari posisi skey
                if(strcmp(temp[k].skey, new.skey) > 0){
                    stop = 1;
                }else{
                    k++;
                }
            }

            for(int l = a-1; l >= k; l--) { // menggeser data lama
                temp[l+1] = temp[l];
            }
            temp[k] = new; // memasukan new ke temp
        }

        ftemp = fopen(fileName, "w");
        for(int i = 0; i < a; i++) { // flush semua data
            fprintf(ftemp, "%s %s\n", temp[i].skey, temp[i].sname);
        }
        fprintf(ftemp, "%s %s\n", "####", "####");
        fclose(ftemp);
        printf("Data berhasil ditambahkan\n");
    }else{
        printf("skey %s sudah ada\n", new.skey);
    }
}

void UPDm(int n, atr obj[], atr new){ // void tempat melakukan update di file utama
    atr temp[65];
    int a = 0;

    FILE *ftemp;
    ftemp = fopen("TabelPrimary.txt", "r");
    while(strcmp(obj[a].fkey, "####") != 0){
        fscanf(ftemp, "%s %s %s %s %s\n",
            obj[a].fkey, obj[a].cont,
            obj[a].kskill,obj[a].knote,&obj[a].score);
        a++;
    }

    a = 0;
    do{
        temp[a] = obj[a]; // menyalin data obj ke temp, temp yang di otak atik
        a++;
    }while(strcmp(obj[a].fkey, "####") != 0);

    fclose(ftemp);

    int k = 0, stop = 0;
    while((k < a) && (stop == 0)){
        if(strcmp(temp[k].fkey, new.fkey) == 0){ // mencari fkey yang sesuai
            temp[k] = new;
            stop = 1;
        }else{
            k++;
        }
    }

    if(stop == 0){ // fkey yang di cari tidak ada
        printf("Tidak ada key yang sesuai!!!\n");
    }else{
        ftemp = fopen("TabelPrimary.txt", "w");
        for(int i = 0; i < a; i++) { // flush semua data
            fprintf(ftemp, "%s %s %s %s %s\n", temp[i].fkey, temp[i].cont, 
                    temp[i].kskill, temp[i].knote,temp[i].score);
        }
        fprintf(ftemp, "%s %s %s %s %s\n", "####", "####", "####", "####", -999);
        fclose(ftemp);
        printf("Data berhasil di UPDATE\n");
    }
}

void UPD(int n, atr obj[], atr new, char fileName[]){ // void tempat melakukan update di file sampingan
    atr temp[65];

    FILE *ftemp;
    ftemp = fopen(fileName, "r");
    for(int i = 0; i < n; i++) { // membaca isi data didalam file
        fscanf(ftemp, "%s %s\n", obj[i].skey, obj[i].sname);
    }

    int a = 0;
    do{
        temp[a] = obj[a]; // memasukan data obj ke temp, temp yang kita otak atik
        a++;
    }while(strcmp(obj[a].skey, "####") != 0);
    
    fclose(ftemp);

    int k = 0, stop = 0;
    while((k < a) && (stop == 0)){
        if(strcmp(temp[k].skey, new.skey) == 0){ // mencari skey yang sesuai
            temp[k] = new;
            stop = 1;
        }else{
            k++;
        }
    }

    if(stop == 0){
        printf("Tidak ada key yang sesuai!!!\n");
    }else{
        ftemp = fopen(fileName, "w");
        for(int i = 0; i < a; i++) { // flush semua data
            fprintf(ftemp, "%s %s\n", temp[i].skey, temp[i].sname);
        }
        fprintf(ftemp, "%s %s\n", "####", "####");
        fclose(ftemp);
        printf("Data berhasil di UPDATE\n");
    }
}

void DELm(int n, atr obj[]){ // void melakukan delete pada file utama
    atr temp[65], new;
    int a = 0;

    printf("masukan fkey dari data yang ingin di DELETE: ");
    scanf("%s", new.fkey);

    FILE *ftemp;
    ftemp = fopen("TabelPrimary.txt", "r");
    while(strcmp(obj[a].fkey, "####") != 0){
        fscanf(ftemp, "%s %s %s %s %s\n",
            obj[a].fkey, obj[a].cont,
            obj[a].kskill,obj[a].knote,&obj[a].score);
        a++;
    }

    a = 0;
    do{
        temp[a] = obj[a]; // memasukan data obj ke temp, temp yang kita otak atik
        a++;
    }while(strcmp(obj[a].fkey, "####") != 0);
    
    fclose(ftemp);

    int k = 0, stop = 0;
    while((k < a) && (stop == 0)){
        if(strcmp(temp[k].fkey, new.fkey) == 0){ // mencari fkey yang sesuai
            for(int i = k; i < (n-1); i++) { // timpa nilai setelahnya ke nilai sekarang
                temp[i] = temp[i+1];
            }
            n--; // kurangi banyak data
            stop = 1;
        }else{
            k++;
        }
    }

    if(stop == 0){
        printf("Tidak ada key yang sesuai!!!\n");
    }else{
        ftemp = fopen("TabelPrimary.txt", "w");
        for(int i = 0; i < (a-1); i++) { // flush semua data
            fprintf(ftemp, "%s %s %s %s %s\n", temp[i].fkey, temp[i].cont, 
                    temp[i].kskill, temp[i].knote,temp[i].score);
        }
        fprintf(ftemp, "%s %s %s %s %s\n", "####", "####", "####", "####", -999);
        fclose(ftemp);
    }
}

void DEL(int n, atr obj[], char fileName[]){ // void melakukan delete pada file sampigan
    atr temp[65], new;

    printf("masukan skey dari data yang ingin di DELETE: ");
    scanf("%s", new.skey);

    FILE *ftemp;
    ftemp = fopen(fileName, "r");
    for(int i = 0; i < n; i++) { // membaca semua data di dalam file
        fscanf(ftemp, "%s %s\n", obj[i].skey, obj[i].sname);
    }

    int a = 0;
    do{
        temp[a] = obj[a]; // memasukan data obj ke temp, temp yang kita otak atik
        a++;
    }while(strcmp(obj[a].skey, "####") != 0);
    
    fclose(ftemp);

    int k = 0, stop = 0;
    while((k < a) && (stop == 0)){
        if(strcmp(temp[k].skey, new.skey) == 0){ // mencari skey yang sesuai
            for(int i = k; i < (n-1); i++) { // menimpa nilai setelahnya ke nilai sekarang
                temp[i] = temp[i+1];
            }
            n--; // kurangai banyak data sekarang
            stop = 1;
        }else{
            k++;
        }
    }

    if(stop == 0){
        printf("Tidak ada key yang sesuai!!!\n");
    }else{
        ftemp = fopen(fileName, "w");
        for(int i = 0; i < (a-1); i++) { // flush semua data
            fprintf(ftemp, "%s %s\n", temp[i].skey, temp[i].sname);
        }
        fprintf(ftemp, "%s %s\n", "####", "####");
        fclose(ftemp);
    }
}

void DELf(int aP, int aNo, int As, atr obj[]){ // void tempat percabangan delete
    char comd[129];

    LIST();
    printf("Masukan nama file:\n");
    printf(">>> ");
    scanf("%s", comd);
    printf("\n");

    if(strcmp(comd, "TabelPrimary.txt") == 0){
        DELm(aP, obj);
    }else if(strcmp(comd, "FighterComplete.txt") == 0){
        printf("Table complete tidak bisa di akses secara langsung\n");
    }else if(strcmp(comd, "Race.txt") == 0){
        DEL(As, obj, "Race.txt");
    }else if(strcmp(comd, "NoteTable.txt") == 0){
        DEL(aNo, obj, "NoteTable.txt");
    }else{
        printf("File tidak ditemukan!\n");
    }

    printf("\n");
}

void SELm(int n, atr obj[]){
    atr temp[65];
    int a = 0;

    FILE *ftemp;
    ftemp = fopen("TabelPrimary.txt", "r");
    while(strcmp(obj[a].fkey, "####") != 0){
        fscanf(ftemp, "%s %s %s %s %s\n",
            obj[a].fkey, obj[a].cont,
            obj[a].kskill,obj[a].knote, obj[a].score);
        a++;
    }
    a = 0;
    do{
        temp[a] = obj[a]; // memasukan data obj ke temp, temp yang kita otak atik
        a++;
    }while(strcmp(obj[a].fkey, "####") != 0);
    
    fclose(ftemp);

    int Dcont, Dskill, Dnote, Dscore;
    Dcont = 7;
    for(int i = 0; i < n; i++) {
        if(strlen(temp[i].cont) > Dcont){
            Dcont = strlen(temp[i].cont);
        }
    }
    Dskill = 5;
    for(int i = 0; i < n; i++) {
        if(strlen(temp[i].kskill) > Dskill){
            Dskill = strlen(temp[i].kskill);
        }
    }
    Dnote = 4;
    for(int i = 0; i < n; i++) {
        if(strlen(temp[i].knote) > Dnote){
            Dnote = strlen(temp[i].knote);
        }
    }    
    Dscore = 5;
    for(int i = 0; i < n; i++) {
        if(strlen(temp[i].score) > Dscore){
            Dscore = strlen(temp[i].score);
        }
    }

    for(int i = 0; i < (a + 4); i++) {
        if((i == 0) || (i == 2) || (i == (a + 3))){
            printf("+");
            for(int j = 0; j < 6; j++){
                printf("-");
            }

            printf("+");
            for(int j = 0; j < (Dcont + 2); j++) {
                printf("-");
            }
            
            printf("+");
            for(int j = 0; j < (Dskill + 2); j++){
                printf("-");
            }
            printf("+");
            for(int j = 0; j < (Dnote + 2); j++){
                printf("-");
            }

            printf("+");
            for(int j = 0; j < (Dscore + 2); j++) {
                printf("-");
            }

            printf("+");
        }else if(i == 1){
            printf("| fkey ");
            
            printf("| Content ");
            if (Dcont > strlen("content")){
                int sel = Dcont - strlen("content");
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }
            
            printf("| Skill ");
            if (Dskill > strlen("skill")){
                int sel = Dskill - strlen("skill");
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }

            printf("| Note ");
            if (Dnote > strlen("Note")){
                int sel = Dnote - strlen("Note");
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }

            printf("| Score ");
            if(Dscore > strlen("score")){
                int sel = Dscore - strlen("score");
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }
            printf("|");
        }else{
            printf("| %s ", temp[i - 3].fkey);

            printf("| %s ", temp[i - 3].cont);
            if (Dcont > strlen(temp[i - 3].cont)){
                int sel = Dcont - strlen(temp[i - 3].cont);
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }

            printf("| %s ", temp[i - 3].kskill);
            if (Dskill > strlen(temp[i - 3].kskill)){
                int sel = Dskill - strlen(temp[i - 3].kskill);
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }
            printf("| %s ", temp[i - 3].knote);
            if (Dnote > (strlen(temp[i - 3].knote))){
                int sel = Dnote - (strlen(temp[i - 3].knote));
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }

            printf("| %s ", temp[i - 3].score);
            if(Dscore > strlen(temp[i - 3].score)){
                int sel = Dscore - strlen(temp[i - 3].score);
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }
            printf("|");
        }
        printf("\n");
    }
}

void SEL(int n, atr obj[], char fileName[]){
    atr temp[65];

    FILE *ftemp;
    ftemp = fopen(fileName, "r");
    for(int i = 0; i < n; i++) { // membaca semua data di dalam file
        fscanf(ftemp, "%s %s\n", obj[i].skey, obj[i].sname);
    }

    int a = 0;
    do{
        temp[a] = obj[a]; // memasukan data obj ke temp, temp yang kita otak atik
        a++;
    }while(strcmp(obj[a].skey, "####") != 0);
    
    fclose(ftemp);

    int Dsname = 5;
    for(int i = 0; i < n; i++){
        if(strlen(temp[i].sname) > Dsname){
            Dsname = strlen(temp[i].sname);
        }
    }

    for(int i = 0; i < (a + 4); i++){
        if((i == 0) || (i == 2) || (i == (a + 3))){
            printf("+");
            for(int j = 0; j < 6; j++){
                printf("-");
            }
            
            printf("+");
            
            for(int j = 0; j < (Dsname + 2); j++){
                printf("-");
            }
            printf("+");
        }else if(i == 1){
            printf("| skey ");
            printf("| sname ");
            if(Dsname > strlen("sname")){
                int sel = Dsname - strlen("sname");
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }
            printf("|");
        }else{
            printf("| %s ", temp[i - 3].skey);
            printf("| %s ", temp[i -3].sname);
            if(Dsname > strlen(temp[i - 3].sname)){
                int sel = Dsname - strlen(temp[i - 3].sname);
                for(int j = 0; j < sel; j++){
                    printf(" ");
                }
            }
            printf("|");
        }
        printf("\n");
    }
}

void SELf(int aN, int aNo, int As, atr obj[]){
    char comd[129];

    LIST();
    printf("Masukan nama file yang ingin dilihat:\n");
    printf(">>> ");
    scanf("%s", comd);
    printf("\n");

    if(strcmp(comd, "TabelPrimary.txt") == 0){
        SELm(aN, obj);
    }else if(strcmp(comd, "TableComplete.txt") == 0){
        printf("Table complete tidak bisa di akses secara langsung\n");
    }else if(strcmp(comd, "SkillTable.txt") == 0){
        SEL(As, obj, "SkillTable.txt");
    }else if(strcmp(comd, "NoteTable.txt") == 0){
        SEL(aNo, obj, "NoteTable.txt");
    }else{
        printf("File tidak ditemukan!\n");
    }

    printf("\n");
}