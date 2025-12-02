#include "head.h"

int main() {
    film list[100]; // tipe bentukan untuk film
    option genre[100]; // tipe bentukan untuk optiom genre
    option studio[100]; // tipe bentukan untuk film stodio
    int idx1 = 0, idx2=0, idx3=0;

    read(&idx1, list, "Film.txt"); // prosedur membaca bagian film.txt
    readOption(&idx2, genre, "Genre.txt"); // prosedur membaca bagian genre.txt
    readOption(&idx3, studio, "Studio.txt"); // prosedur memnbaca bagian studio.txt

    join(list, genre, studio); // menggabungkan secondary foreign key

    printf("List Film:\n");
    for(int i=0; i<idx1; i++) { // hasilnya di print ke terminal
        printf("%s %s %d %s %s\n", list[i].kode, list[i].judul, list[i].waktu, list[i].gen, list[i].std);
    }

    return 0;
}