#include <stdio.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{ // definisi tipe bentukan atr
    char fkey[5], cont[256], skey[5], sname[256],
        kskill[256], knote[256],
        scont[256], sskill[256], snote[256],
        score[256];
}atr;

void Salam(); // salam pembuka
void MENU(); // menampilkan menu
void LIST(); // menampilkan list file

extern int indeks; // indeks pembacaan kata
extern int panjangKata; // panjang kata yang dibaca
extern char cw[129]; // kata yang sedang dibaca

void STARTWORD(char pita[]); // memulai pembacaan kata
void RESETWORD(); // mereset pembacaan kata
void INCWORD(char pita[]); // menaikan pembacaan kata ke kata berikutnya
void INCWORD(char pita[]); // menaikan pembacaan kata ke kata berikutnya
char* GETWORD(); // mengembalikan kata yang sedang dibaca
int GETPANJANGKATA(); // mengembalikan panjang kata yang sedang dibaca
int EOPWORD(char pita[]); // mengecek apakah sudah EOP atau belum

void mReadFile(int *a, int *aP, atr sc[]); // membaca file utama
void readFile(int *a, int *b, int *tF, atr sc[], char fileName[]); // membaca file sampingan
void mMerge(int *aN, int *aR, int *aU, int *tF, atr sc[], char fileName[]); // mengabungkan file

void refresh(); // memperbaharui data

void INSm(int n, atr obj[], atr new); // void tempat melakukan insert di file utama
void INS(int n, atr obj[], atr new, char fileName[]); // void tempat melakukan insert di file sampingan

void UPDm(int n, atr obj[], atr new); // void tempat melakukan update di file utama
void UPD(int n, atr obj[], atr new, char fileName[]); // void tempat melakukan update di file sampingan

void DELm(int n, atr obj[], atr new); // void tempat melakukan delete di file utama
void DEL(int n, atr obj[], atr new, char fileName[]); // void tempat melakukan delete di file sampingan

void SHOm(int n, atr obj[], int r); // void melakukan show pada file utama
void SHO(int n, atr obj[], char fileName[]); // void melakukan show pada file sampingan

void Thx(); // ucapan terima kasih