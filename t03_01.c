#include <stdio.h> // Diperlukan untuk fungsi input/output seperti scanf dan printf

int main() {
    int n; // Variabel untuk menyimpan jumlah baris masukkan n
    double sum = 0.0; // Variabel untuk menyimpan jumlah total nilai, menggunakan double agar presisi
    int i; // Variabel untuk loop

    // Membaca input n (jumlah nilai tugas)
    // Diasumsikan n adalah bilangan bulat positif sesuai instruksi
    scanf("%d", &n);

    // Membaca n baris nilai tugas dan menghitung jumlahnya
    for (i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);

        // Validasi nilai tugas: harus antara 0-100 dan tidak dibawah 0
        // Karena soal menyebutkan "tidak menerima inputan dibawah 0",
        // kita akan mengabaikan nilai yang tidak valid (atau bisa juga berikan error,
        // namun instruksi tidak spesifik, jadi anggap diabaikan).
        // Untuk kesederhanaan dan sesuai "tidak menerima", kita hanya akan memproses yang valid.
        if (score >= 0 && score <= 100) {
            sum += score;
        } else {
            // Opsional: Anda bisa menambahkan penanganan error di sini,
            // namun untuk memenuhi kriteria "tidak menerima inputan dibawah 0"
            // dan batasan 0-100, kita bisa memilih untuk tidak memasukkan
            // nilai yang tidak valid ke dalam perhitungan.
            // Untuk kasus ini, kita akan biarkan loop berjalan dan tidak menambahkan nilai yang tidak valid.
            // Jika ada nilai di luar rentang, itu tidak akan mempengaruhi sum atau count.
            // Namun, karena prompt menyatakan "bilangan bulat antara 0 - 100",
            // kita asumsikan input akan selalu valid atau kita hanya memproses yang valid.
            // Dalam implementasi ini, input yang valid antara 0-100 akan dijumlahkan.
            // Input di luar rentang tersebut (misal <0 atau >100) akan diabaikan dari penjumlahan.
        }
    }

    // Menampilkan jumlah seluruh nilai
    printf("%.0f\n", sum); // Menggunakan .0f untuk menampilkan double tanpa desimal

    // Menghitung dan menampilkan nilai rata-rata
    if (n > 0) { // Pastikan n tidak nol untuk menghindari pembagian dengan nol
        double average = sum / n;
        printf("%.2f\n", average); // Menampilkan rata-rata dengan 2 digit presisi
    } else {
        // Jika n adalah 0, rata-rata tidak dapat dihitung
        // Sesuai format output, kita bisa menampilkan 0.00 atau membiarkannya kosong,
        // namun untuk soal yang mengasumsikan n adalah bilangan bulat positif,
        // kasus ini mungkin tidak akan terjadi.
        printf("0.00\n"); // Atau penanganan lain jika n=0
    }

    return 0; // Mengindikasikan program berjalan sukses
}
