#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf

int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan (jumlah mahasiswa)
    
    // Membaca nilai n dari input pengguna (baris pertama)
    printf("Masukkan jumlah mahasiswa (n): "); // Prompt opsional, bisa dihapus jika output harus bersih
    scanf("%d", &n);

    // Deklarasi Variable Length Array (VLA) untuk menyimpan nilai-nilai mahasiswa
    // VLA adalah fitur standar C99 dan didukung oleh GCC.
    // Jika compiler tidak mendukung VLA atau ingin lebih portabel (misal C89),
    // bisa menggunakan array statis dengan ukuran maksimum tertentu (misal: int scores[100];)
    // atau alokasi dinamis dengan malloc().
    int scores[n]; 
    int sum = 0;    // Variabel untuk mengakumulasikan total jumlah nilai, diinisialisasi dengan 0
    double average; // Variabel untuk menyimpan hasil rata-rata, menggunakan double untuk presisi
    int count_above_average = 0; // Variabel untuk menghitung mahasiswa dengan nilai >= rata-rata

    // --- Iterasi Pertama: Membaca nilai-nilai ke dalam array dan menghitung jumlah total ---
    printf("Masukkan %d nilai mahasiswa:\n", n); // Prompt opsional
    for (int i = 0; i < n; i++) {
        // Membaca nilai mahasiswa saat ini dan menyimpannya ke dalam array
        scanf("%d", &scores[i]);
        // Menambahkan nilai saat ini ke total jumlah
        sum += scores[i]; 
    }

    // Menghitung rata-rata
    // Melakukan type casting eksplisit pada 'sum' ke 'double' sebelum pembagian
    // agar pembagian dilakukan sebagai floating-point dan dan 'n' juga terpromosi ke double.
    if (n > 0) { // Menghindari pembagian dengan nol jika n adalah 0
        average = (double)sum / n;
    } else {
        average = 0.0; // Jika tidak ada nilai, rata-rata adalah 0
    }

    // --- Iterasi Kedua: Membandingkan setiap nilai dalam array dengan rata-rata ---
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++; // Menambah hitungan jika nilai memenuhi kriteria
        }
    }

    // --- Menampilkan Output Sesuai Spesifikasi ---
    // Baris 1: Jumlah total nilai
    printf("%d\n", sum);

    // Baris 2: Nilai rata-rata (Float, presisi 2 desimal)
    printf("%.2f\n", average);

    // Baris 3: Jumlah mahasiswa dengan nilai >= rata-rata
    printf("%d\n", count_above_average);

    return 0; // Mengindikasikan bahwa program berjalan dengan sukses
}