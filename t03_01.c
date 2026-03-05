#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf

int main() {
    int n;          // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int current_num; // Variabel sementara untuk setiap bilangan yang dimasukkan
    int sum = 0;    // Variabel untuk mengakumulasikan total jumlah bilangan, diinisialisasi dengan 0
    double average; // Variabel untuk menyimpan hasil rata-rata, menggunakan double untuk presisi

    // Membaca nilai n dari input pengguna (baris pertama)
    // "%d" untuk membaca integer, &n adalah alamat memori tempat nilai akan disimpan
    scanf("%d", &n);

    // Loop sebanyak n kali untuk membaca setiap bilangan berikutnya
    for (int i = 0; i < n; i++) {
        // Membaca bilangan bulat saat ini
        scanf("%d", &current_num);
        // Menambahkan bilangan saat ini ke total jumlah
        sum += current_num; // Ini sama dengan sum = sum + current_num;
    }

    // Menghitung rata-rata.
    // Penting: Melakukan type casting eksplisit pada 'sum' ke 'double' sebelum pembagian
    // agar pembagian dilakukan sebagai floating-point dan bukan integer, yang akan memotong desimal.
    // 'n' secara implisit akan di-promote ke double karena salah satu operand adalah double.
    average = (double)sum / n;

    // Menampilkan total akumulasi (sum) sesuai format yang diminta (hanya angka, baris pertama)
    printf("%d\n", sum);

    // Menampilkan rata-rata dengan 2 digit presisi di belakang koma (baris kedua)
    // "%.2f" adalah format specifier untuk double/float dengan 2 digit desimal
    printf("%.2f\n", average);

    return 0; // Mengindikasikan bahwa program berjalan dengan sukses
}