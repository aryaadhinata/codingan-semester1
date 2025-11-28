#include <stdio.h>

int main() {
    int xR, yR;
    int n;

    printf("Masukkan posisi awal Robo (x y): ");
    scanf("%d %d", &xR, &yR);

    printf("Masukkan jumlah objek di peta: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int xO, yO;
        int dx, dy;
        int a, b, c; // a=kuning, b=biru, c=merah

        printf("\n==============================\n");
        printf("Objek %d\n", i);
        printf("Masukkan posisi objek (x y): ");
        scanf("%d %d", &xO, &yO);

        dx = xO - xR; // jarak sisa di dalam koordinat x
        dy = yO - yR; // jarak sisa di dalam koordinat y

        // SOLUSI SPL DARI MATRKS
        a = 0;                  // Kuning
        b = dx + dy;            // Biru
        c = dy + b;             // Merah

        printf("Hasil: YA, objek dapat dicapai\n");

        printf("Pergerakan tombol:\n");
        printf("- Kuning : %d kali\n", a);
        printf("- Biru   : %d kali\n", b);
        printf("- Merah  : %d kali\n", c);

        // Menjelaskan jika ada arah terbalik
        if (b < 0)
            printf("  (Biru bergerak berlawanan arah sebanyak %d kali)\n", -b);
        if (c < 0)
            printf("  (Merah bergerak berlawanan arah sebanyak %d kali)\n", -c);
    }
	
	// kenapa kuning selalu 0 karena kuning bukan bagian dari basis
	
    return 0;
}
