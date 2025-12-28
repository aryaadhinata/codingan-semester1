#include "head.h"
 
/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    Salam(); // salam pembuka
    /*
        a    : banyak data utama
        aP   : banyak data primary
        aS   : banyak data skill
        aN   : banyak data note
        tfKey: tanda pembacaan skey keberapa
    */
    int a = 0, aP = 0, aS = 0, 
        aN = 0, tfKey = 0;
    atr comp[65]; // array penampung data sementara

    mReadFile(&a, &aP, comp); // membaca file utama
    
    readFile(&a, &aS, &tfKey, comp, "SkillTable.txt"); // membaca file skill
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt"); // mengabungkan file utama dan skill

    readFile(&a, &aN, &tfKey, comp, "NoteTable.txt"); // membaca file note
    mMerge(&aP, &aS, &aN, &tfKey, comp, "TableComplete.txt"); // mengabungkan file utama, skill dan note

    char pita[513]; // pita penampung input user
    
    MENU(); // menampilkan menu
    LIST(); // menampilkan list file
    
    int condition = 0; // penanda keluar program
    do{ // loop utama program
        printf("DBMS [Arya]>> "); // prompt input
        refresh(); // memperbaharui data
        
        scanf(" %512[^\n]s", pita); // membaca input user

        STARTWORD(pita); // memulai pembacaan kata
        
        printf("\n");
        if((strcmp(GETWORD(), "INSERT") == 0 )|| (strcmp(GETWORD(), "1") == 0 )){ // pengkondisiann perintah insert
            INCWORD(pita); // menaikan ke kata berikutnya
            if(strcmp(GETWORD(), "TabelPrimary.txt") == 0){ // insert ke file utama
                atr new; // variabel penampung data baru

                for(int i = 0; i < 5; i++) { // membaca 5 input berikutnya
                    INCWORD(pita); // menaikan ke kata berikutnya
                    switch (i){ // switch case untuk menampung data baru
                        case 0:{
                            strcpy(new.fkey, GETWORD());
                            break;
                        }case 1:{
                            strcpy(new.cont, GETWORD());
                            break;
                        }case 2:{
                            strcpy(new.kskill, GETWORD());
                            break;
                        }case 3:{
                            strcpy(new.knote, GETWORD());
                            break;
                        }case 4:{
                            strcpy(new.score, GETWORD());
                            break;
                        }
                    }
                }

                INSm(aP, comp, new); // melakukan insert
            }else if(strcmp(GETWORD(), "SkillTable.txt") == 0){ // insert ke file skill
                atr new; // variabel penampung data baru

                for(int i = 0; i < 2; i++) { // membaca 2 input berikutnya
                    INCWORD(pita); // menaikan ke kata berikutnya
                    switch (i){ // switch case untuk menampung data baru
                        case 0:{
                            strcpy(new.skey, GETWORD());
                            break;
                        }case 1:{
                            strcpy(new.sname, GETWORD());
                            break;
                        }
                    }
                }
                
                INS(aS, comp, new, "SkillTable.txt"); // melakukan insert
            }else if(strcmp(GETWORD(), "NoteTable.txt") == 0){ // insert ke file note
                atr new; // variabel penampung data baru

                for(int i = 0; i < 2; i++) { // membaca 2 input berikutnya
                    INCWORD(pita); // menaikan ke kata berikutnya
                    switch (i){ // switch case untuk menampung data baru
                        case 0:{
                            strcpy(new.skey, GETWORD());
                            break;
                        }case 1:{
                            strcpy(new.sname, GETWORD());
                            break;
                        }
                    }
                }
                
                INS(aN, comp, new, "NoteTable.txt"); // melakukan insert
            }else if(strcmp(GETWORD(), "TableComplete.txt") == 0){ // insert ke file join (tidak diperbolehkan)
                printf("ini file join tidak bisa di otak-atik\n");
            }else{ // file tidak ditemukan
                printf("File tidak ditemukan!\n");
            }
        }else if((strcmp(GETWORD(), "UPDATE") == 0) || (strcmp(GETWORD(), "2") == 0)){ // pengkondisian perintah update
            INCWORD(pita); // menaikan ke kata berikutnya
            if(strcmp(GETWORD(), "TabelPrimary.txt") == 0){ // update ke file utama
                atr new; // variabel penampung data baru
                
                for(int i = 0; i < 5; i++) { // membaca 5 input berikutnya
                    INCWORD(pita); // menaikan ke kata berikutnya
                    switch (i){ // switch case untuk menampung data baru
                        case 0:{
                            strcpy(new.fkey, GETWORD());
                            break;
                        }case 1:{
                            strcpy(new.cont, GETWORD());
                            break;
                        }case 2:{
                            strcpy(new.kskill, GETWORD());
                            break;
                        }case 3:{
                            strcpy(new.knote, GETWORD());
                            break;
                        }case 4:{
                            strcpy(new.score, GETWORD());
                            break;
                        }
                    }
                }
                
                UPDm(aP, comp, new); // melakukan update
            }else if(strcmp(GETWORD(), "SkillTable.txt") == 0){ // update ke file skill
                atr new; // variabel penampung data baru

                for(int i = 0; i < 2; i++) { // membaca 2 input berikutnya
                    INCWORD(pita); // menaikan ke kata berikutnya
                    switch (i){ // switch case untuk menampung data baru
                        case 0:{
                            strcpy(new.skey, GETWORD());
                            break;
                        }case 1:{
                            strcpy(new.sname, GETWORD());
                            break;
                        }
                    }
                }

                UPD(aS, comp, new, "SkillTable.txt"); // melakukan update
            }else if(strcmp(GETWORD(), "NoteTable.txt") == 0){ // update ke file note
                atr new; // variabel penampung data baru

                for(int i = 0; i < 2; i++) { // membaca 2 input berikutnya
                    INCWORD(pita); // menaikan ke kata berikutnya
                    switch (i){ // switch case untuk menampung data baru
                        case 0:{ 
                            strcpy(new.skey, GETWORD());
                            break;
                        }case 1:{
                            strcpy(new.sname, GETWORD());
                            break;
                        }
                    }
                }

                UPD(aN, comp, new, "NoteTable.txt"); // melakukan update
            }else if(strcmp(GETWORD(), "TableComplete.txt") == 0){ // update ke file join (tidak diperbolehkan)
                printf("ini file join tidak bisa di otak-atik\n"); 
            }else{ // file tidak ditemukan
                printf("File tidak ditemukan!\n");
            }
        }else if((strcmp(GETWORD(), "DELETE") == 0) || (strcmp(GETWORD(), "3") == 0)){ // pengkondisian perintah delete
            INCWORD(pita); // menaikan ke kata berikutnya
            if(strcmp(GETWORD(), "TabelPrimary.txt") == 0){ // delete ke file utama
                atr new; // variabel penampung data baru
                
                INCWORD(pita); // menaikan ke kata berikutnya
                strcpy(new.fkey, GETWORD()); // menampung fkey yang akan di delete
                
                DELm(aP, comp, new); // melakukan delete
            }else if(strcmp(GETWORD(), "SkillTable.txt") == 0){ // delete ke file skill
                atr new; // variabel penampung data baru

                INCWORD(pita); // menaikan ke kata berikutnya
                strcpy(new.skey, GETWORD()); // menampung skey yang akan di delete
                
                DEL(aS, comp, new, "SkillTable.txt"); // melakukan delete
            }else if(strcmp(GETWORD(), "NoteTable.txt") == 0){ // delete ke file note
                atr new; // variabel penampung data baru

                INCWORD(pita); // menaikan ke kata berikutnya
                strcpy(new.skey, GETWORD()); // menampung skey yang akan di delete
                
                DEL(aN, comp, new, "NoteTable.txt");
            }else if(strcmp(GETWORD(), "FighterComplete.txt") == 0){ // delete ke file join (tidak diperbolehkan)
                printf("Tini file join tidak bisa di otak-atik\n");
            }else{ // file tidak ditemukan
                printf("File tidak ditemukan!\n");
            }
        }else if((strcmp(GETWORD(), "SHOW") == 0) || (strcmp(GETWORD(), "4") == 0)){ // pengkondisian perintah show
            INCWORD(pita); // menaikan ke kata berikutnya
            if(strcmp(GETWORD(), "TableComplete.txt") == 0){ // show file join
                SHOm(aN, comp, 0);
            }else if(strcmp(GETWORD(), "TabelPrimary.txt") == 0){ // show file utama
                SHOm(aN, comp, 1);
            }else if(strcmp(GETWORD(), "SkillTable.txt") == 0){ // show file skill
                SHO(aS, comp, "SkillTable.txt");
            }else if(strcmp(GETWORD(), "NoteTable.txt") == 0){ // show file note
                SHO(aN, comp, "NoteTable.txt");
            }else{ // file tidak ditemukan
                printf("File tidak ditemukan!\n");
            }
        }else if((strcmp(GETWORD(), "HELP") == 0) || (strcmp(GETWORD(), "9") == 0)){ // menampilkan menu bantuan
            MENU(); // menampilkan menu
            LIST(); // menampilkan list file
        }else{ // perintah tidak dikenali
            int mark = 0; // penanda perintah dikenali atau tidak
            while (EOPWORD(pita) == 0){ // loop sampai EOP
                if(strcmp(GETWORD(), "EXIT") == 0 || strcmp(GETWORD(), "0") == 0){ // keluar program
                    Thx(); // ucapan terima kasih
                    condition = 1; // mengubah kondisi keluar program
                    mark = 1; // menandai perintah dikenali
                }
                INCWORD(pita); // menaikan ke kata berikutnya
            }
            if(mark == 0){ // perintah tidak dikenali
                printf("Perintah tidak dikenali!\n");
            }
        }
        
    } while(condition != 1); // loop utama program

    return 0;
}