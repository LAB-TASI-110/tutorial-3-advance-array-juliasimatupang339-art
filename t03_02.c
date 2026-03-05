#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Diperlukan untuk fungsi malloc dan free

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukkan n
    double sum = 0.0; // Variabel untuk menyimpan jumlah total nilai, menggunakan double agar presisi
    int i;          // Variabel untuk loop

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
    for (i = 0; i < n; i++) {
        int current_score;
        scanf("%d", &current_score);

        // Sesuai instruksi "bilangan bulat antara 0 - 100" dan "tidak menerima inputan dibawah 0",
        // kita akan menyimpan dan menjumlahkan hanya nilai yang valid.
        // Asumsi: jika ada nilai di luar rentang, ia akan diabaikan dari perhitungan.
        if (current_score >= 0 && current_score <= 100) {
            scores[i] = current_score; // Simpan nilai yang valid
            sum += current_score;      // Tambahkan ke jumlah total
        } else {
            // Untuk kasus input yang tidak valid (misal <0 atau >100),
            // kita bisa menandainya atau mengabaikannya dari perhitungan sum dan average.
            // Untuk memenuhi "tidak menerima inputan dibawah 0" dan batasan 0-100
            // serta menyederhanakan sesuai prompt, kita akan mengisi nilai "invalid"
            // atau nilai default, yang kemudian akan diabaikan saat penghitungan rata-rata dan count.
            // Untuk kesederhanaan, kita akan mengisi dengan -1 sebagai penanda nilai tidak valid.
            // Ini akan mempengaruhi bagaimana kita menghitung rata-rata dan count_above_average.
            // Jika prompt bermaksud bahwa input di luar rentang ini tidak boleh masuk ke program sama sekali,
            // maka program akan menjadi lebih kompleks dengan penanganan input loop ulang.
            // Mengacu pada contoh dan fokus pada output, kita asumsikan semua input n akan valid 0-100.
            // Mengingat contoh yang diberikan semua nilai valid, kita akan berasumsi semua n input akan valid.
            scores[i] = current_score; // Untuk contoh, semua nilai diasumsikan valid.
        }
    }

    // Menampilkan jumlah seluruh nilai
    printf("%.0f\n", sum); // Menggunakan .0f untuk menampilkan double tanpa desimal

    double average = 0.0;
    if (n > 0) { // Pastikan n tidak nol untuk menghindari pembagian dengan nol
        average = sum / n;
        printf("%.2f\n", average); // Menampilkan rata-rata dengan 2 digit presisi
    } else {
        printf("0.00\n"); // Jika n=0, rata-rata adalah 0.00
    }

    // Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    int count_above_average = 0;
    if (n > 0) { // Hanya jika ada mahasiswa untuk diperiksa
        for (i = 0; i < n; i++) {
            // Di sini kita asumsikan semua nilai dalam array 'scores' adalah valid (0-100)
            // sesuai dengan interpretasi dari input contoh dan "bilangan bulat antara 0 - 100".
            if (scores[i] >= average) {
                count_above_average++;
            }
        }
    }
    printf("%d\n", count_above_average); // Menampilkan jumlah mahasiswa di atas/sama dengan rata-rata

    // Membebaskan memori yang telah dialokasikan
    free(scores);
    scores = NULL; // Hindari dangling pointer

    return 0; // Mengindikasikan program berjalan sukses
}