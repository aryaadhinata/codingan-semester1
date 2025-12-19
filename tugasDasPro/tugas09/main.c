#include "head.h"

int main(){
    char pita1[201],
        pita2[301];
    scanf(" %200[^\n]s", pita1);
    scanf(" %300[^\n]s", pita2);
    
    START(pita1);
    while (EOP() == 0){
        if((nextBlank(pita1) == 1) && (GETIDX() > 1)){
            printf(" ");
        }
        printf("%c", GETCC());
        INC(pita1);
    }
    
    printf("\n_______________________________________\n");
    printf("Daftar Kata-Kata Sesuai Kategori Tarif:\n");
    
    int jumlahPre = 0,
        jumlahReg = 0,
        jumlahFre = 0;

    char premium[300][128], 
        reguler[300][128],
        Free[300][128];

    STARTWORD(pita2);
    while (EOPWORD(pita2) == 0){
        if((GETSUMASCII() != 0) && (GETPANJANGKATA() != 0)){
            if((GETSUMASCII() % 2 == 0) && (GETPANJANGKATA() % 2 == 0)){
                strcpy(premium[jumlahPre], GETWORD());
                jumlahPre++;
            }else if((GETSUMASCII() % 2 == 1) && (GETPANJANGKATA() % 2 == 1)){
                strcpy(reguler[jumlahReg], GETWORD());
                jumlahReg++;
            }else{
                strcpy(Free[jumlahFre], GETWORD());
                jumlahFre++;
            }
        }
        INCWORD(pita2);
    }
    
    printf("\nkata premium:\n");
    if(jumlahPre != 0){
        for(int i = 0; i < jumlahPre; i++) {
            printf("%s\n", premium[i]);
        }
    }else{
        printf("kosong boss\n");
    }
    printf("\nkata reguler:\n");
    if(jumlahReg != 0){
        for(int i = 0; i < jumlahReg; i++) {
            printf("%s\n", reguler[i]);
        }
    }else{
        printf("kosong boss\n");
    }
    printf("\nkata free:\n");
    if(jumlahFre != 0){   
        for(int i = 0; i < jumlahFre; i++) {
            printf("%s\n", Free[i]);
        }
    }else{
        printf("kosong boss\n");
    }
        
    return 0;
}