#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Diperlukan untuk fungsi malloc dan free
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN (untuk inisialisasi min/max)

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukkan n
    double sum = 0.0; // Variabel untuk menyimpan jumlah total nilai, menggunakan double agar presisi
    int i;          // Variabel untuk loop

    // Inisialisasi untuk menemukan nilai minimum dan maksimum
    // Diasumsikan nilai tugas antara 0-100, jadi kita bisa pakai batas yang lebih spesifik
    int min_score = 101; // Nilai maksimum yang mungkin adalah 100, jadi 101 adalah batas atas yang aman
    int max_score = -1;  // Nilai minimum yang mungkin adalah 0, jadi -1 adalah batas bawah yang aman

    // Membaca input n (jumlah nilai tugas)
    // Diasumsikan n adalah bilangan bulat positif sesuai instruksi ("bilangan bulat positif")
    scanf("%d", &n);

    // Alokasi memori untuk menyimpan nilai-nilai tugas
    // Menggunakan malloc agar ukuran array bisa dinamis sesuai input n
    int *scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        printf("Error: Gagal mengalokasikan memori.\n");
        return 1; // Mengindikasikan program berakhir dengan kesalahan
    }

    // Membaca n baris nilai tugas, menyimpannya dalam array, dan menghitung jumlahnya
    // Sesuai dengan batasan "bilangan bulat antara 0 - 100" dan "tidak menerima inputan dibawah 0",
    // kita asumsikan semua input n baris nilai akan berada dalam rentang [0, 100].
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]); // Baca nilai langsung ke dalam array

        sum += scores[i];      // Tambahkan ke jumlah total

        // Update nilai minimum dan maksimum
        if (scores[i] < min_score) {
            min_score = scores[i];
        }
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    // 1. Menampilkan jumlah seluruh nilai
    printf("%.0f\n", sum); // Menggunakan .0f untuk menampilkan double tanpa desimal

    double average = 0.0;
    if (n > 0) { // Pastikan n tidak nol untuk menghindari pembagian dengan nol
        average = sum / n;
        // 2. Menampilkan rata-rata dengan 2 digit presisi
        printf("%.2f\n", average);
    } else {
        printf("0.00\n"); // Jika n=0, rata-rata adalah 0.00
    }

    // 3. Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    int count_above_average = 0;
    if (n > 0) { // Hanya jika ada mahasiswa untuk diperiksa
        for (i = 0; i < n; i++) {
            if (scores[i] >= average) {
                count_above_average++;
            }
        }
    }
    printf("%d\n", count_above_average); // Menampilkan jumlah mahasiswa di atas/sama dengan rata-rata

    // 4. Menampilkan rentang nilai (maksimum - minimum)
    if (n > 0) { // Hanya jika ada nilai untuk dihitung rentangnya
        int range = max_score - min_score;
        printf("%d\n", range);
    } else {
        // Jika n=0, rentang tidak terdefinisi atau bisa dianggap 0
        printf("0\n"); // Atau penanganan lain sesuai kebutuhan (misal, tidak menampilkan apapun)
    }

    // Membebaskan memori yang telah dialokasikan
    free(scores);
    scores = NULL; // Hindari dangling pointer

    return 0; // Mengindikasikan program berjalan sukses
}
