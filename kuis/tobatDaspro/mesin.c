#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pebaikan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void star(int a){ // menggambar bintang dengan ketebalan a
    for(int i = 0; i < a; i++) { // loop sebanyak a kali
        printf("x");
    }
}

void space(int a){ // menggambar spasi dengan ketebalan a
    for(int i = 0; i < a; i++) { // loop sebanyak a kali
        printf(" ");
    }
}

void str(int a){ // menggambar pola untuk "string"
    for(int i = 0;i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 6; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 6; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 3; l++){
                        star(a);
                    }
                    for(int l = 0; l < 11; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 3; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    space(a);
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 2:{ // baris ketiga
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}

void con(int a){ // menggambar pola untuk "conio"
    for(int i = 0; i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 13; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 5; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 21; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama 
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 2:{ // baris ketiga
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}

void stio(int a){ // menggambar pola untuk "stdio"
    for(int i = 0; i < 2; i++){  // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 5; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 3; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 8; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            } 
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 2:{ // baris ketiga
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }  
}

void mth(int a){ // menggambar pola untuk "math" 
    for(int i = 0; i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 12; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 12; l++){
                        space(a);
                    }
                    for(int l = 0; l < 3; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 2:{ // baris ketiga
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}

void std(int a){ // menggambar pola untuk "stdlib"
    for(int i = 0; i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 3; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            } 
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 2:{ // baris ketiga
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}

void cty(int a){ // menggambar pola untuk "ctype"
    for(int i = 0; i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 6; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 6; l++){
                        space(a);
                    }
                    for(int l = 0; l < 3; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 2:{ // baris ketiga
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}

void mllc(int a){ // menggambar pola untuk "malloc"
    for(int i = 0; i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 11; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 9; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 12; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 10; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 2:{ // baris ketiga
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    space(a);
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}

void tme(int a){ // menggambar pola untuk "time"
    for(int i = 0; i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 8; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 3; l++){
                        star(a);
                    }
                    for(int l = 0; l < 9; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }    
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }                    
                    break;
                }
                case 2:{ // baris ketiga
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}

void no(int a){ // menggambar pola untuk input selain yang diatas
    for(int i = 0; i < 2; i++){ // bagian atas pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 2; k > i; k--){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 9; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 11; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }    
    for(int i = 0; i < 3; i++){ // bagian bawah pola
        for(int j = 0; j < a; j++){ // loop sebanyak a kali untuk ketebalan
            for(int k = 0; k < i; k++){ // menggambar spasi sebelum bintang
                space(a);
            }
            star(a); // menggambar bintang pertama di setiap baris
            switch (i){ // menggambar pola sesuai dengan baris
                case 0:{ // baris pertama
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    for(int l = 0; l < 2; l++){
                        star(a);
                    }
                    for(int l = 0; l < 3; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 4; l++){
                        space(a);
                    }
                    break;
                }
                case 1:{ // baris kedua
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }                    
                    break;
                }
                case 2:{ // baris ketiga
                    space(a);
                    star(a);
                    space(a);
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    star(a);
                    for(int l = 0; l < 2; l++){
                        space(a);
                    }
                    break;
                }
            }
            star(a); // menggambar bintang di akhir baris
            printf("\n"); // pindah ke baris berikutnya
        }
    }
}