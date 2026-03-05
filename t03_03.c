#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN (opsional, untuk inisialisasi min/max)

int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan (jumlah mahasiswa)
    
    // Membaca nilai n dari input pengguna (baris pertama)
    // printf("Masukkan jumlah mahasiswa (n): "); // Prompt opsional
    scanf("%d", &n);

    // Deklarasi Variable Length Array (VLA) untuk menyimpan nilai-nilai mahasiswa
    // VLA didukung oleh GCC di bawah standar C99/C11.
    int scores[n]; 
    int sum = 0;    // Variabel untuk mengakumulasikan total jumlah nilai, diinisialisasi dengan 0
    double average; // Variabel untuk menyimpan hasil rata-rata, menggunakan double untuk presisi
    int count_above_average = 0; // Variabel untuk menghitung mahasiswa dengan nilai >= rata-rata
    
    // Inisialisasi min_score dan max_score dengan nilai ekstrim atau nilai pertama
    // Menginisialisasi dengan INT_MAX dan INT_MIN dari <limits.h> adalah cara robust.
    // Atau, bisa inisialisasi dengan scores[0] setelah membaca nilai pertama.
    int min_score = INT_MAX; // Nilai terbesar yang mungkin untuk int
    int max_score = INT_MIN; // Nilai terkecil yang mungkin untuk int

    // --- Iterasi Pertama: Membaca nilai-nilai ke dalam array, menghitung jumlah total, dan menentukan min/max ---
    // printf("Masukkan %d nilai mahasiswa:\n", n); // Prompt opsional
    for (int i = 0; i < n; i++) {
        // Membaca nilai mahasiswa saat ini dan menyimpannya ke dalam array
        scanf("%d", &scores[i]);
        
        // Menambahkan nilai saat ini ke total jumlah
        sum += scores[i]; 

        // Memperbarui nilai minimum
        if (scores[i] < min_score) {
            min_score = scores[i];
        }

        // Memperbarui nilai maksimum
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    // Menghitung rata-rata
    // Melakukan type casting eksplisit pada 'sum' ke 'double' sebelum pembagian
    if (n > 0) { // Menghindari pembagian dengan nol jika n adalah 0
        average = (double)sum / n;
    } else {
        average = 0.0; // Jika tidak ada nilai, rata-rata adalah 0
        min_score = 0; // Atur min/max/range ke 0 jika tidak ada data
        max_score = 0;
    }

    // --- Iterasi Kedua: Membandingkan setiap nilai dalam array dengan rata-rata ---
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++; // Menambah hitungan jika nilai memenuhi kriteria
        }
    }

    // Menghitung rentang nilai (Range)
    int range = max_score - min_score;
    // Jika n=0, min_score dan max_score akan tetap INT_MAX/INT_MIN atau 0.
    // Pastikan range juga 0 untuk kasus n=0.
    if (n == 0) {
        range = 0;
    }

    // --- Menampilkan Output Sesuai Spesifikasi ---
    // Baris 1: Jumlah total nilai
    printf("%d\n", sum);

    // Baris 2: Nilai rata-rata (Float, presisi 2 desimal)
    printf("%.2f\n", average);

    // Baris 3: Jumlah mahasiswa dengan nilai >= rata-rata
    printf("%d\n", count_above_average);

    // Baris 4: Rentang nilai / Range
    printf("%d\n", range);

    return 0; // Mengindikasikan bahwa program berjalan dengan sukses
}