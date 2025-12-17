#include <stdio.h>
#include <math.h>

// Definisikan fungsi yang akan diintegralkan
double f(double x) {
    return 1.0 / (1.0 + x);   // contoh: f(x) = 1/(1+x)
}

int main() {
    double a, b, h, integral, sum_odd = 0, sum_even = 0;
    int n;

    printf("Masukkan batas bawah a: ");
    scanf("%lf", &a);
    printf("Masukkan batas atas b: ");
    scanf("%lf", &b);
    printf("Masukkan jumlah segmen n (harus genap): ");
    scanf("%d", &n);

    // Validasi n
    if (n % 2 != 0) {
        printf("Error: n harus bilangan genap!\n");
        return 1;
    }

    // Hitung lebar segmen
    h = (b - a) / n;

    // Hitung jumlah untuk indeks ganjil dan genap
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 1) {
            sum_odd += f(x);   // indeks ganjil
        } else {
            sum_even += f(x);  // indeks genap
        }
    }

    // Rumus Simpson 1/3
    integral = (h / 3.0) * (f(a) + 4 * sum_odd + 2 * sum_even + f(b));

    // Tampilkan hasil
    printf("Hasil integral (Simpson 1/3) = %.6f\n", integral);

    return 0;
}
