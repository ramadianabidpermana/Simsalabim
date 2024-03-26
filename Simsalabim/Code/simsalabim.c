#include <stdio.h>

// Fungsi untuk mengecek apakah suatu tahun adalah tahun kabisat
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1; // Tahun kabisat
    else
        return 0; // Bukan tahun kabisat
}

// Fungsi untuk menentukan jumlah hari dalam suatu bulan
int daysInMonth(int month, int year) {
    switch(month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return (isLeapYear(year) ? 29 : 28);
        default:
            return 31;
    }
}

// Fungsi untuk menambahkan satu hari ke tanggal yang diberikan
void addOneDay(int *day, int *month, int *year) {
    if (*day < daysInMonth(*month, *year)) {
        (*day)++;
    } else {
        *day = 1;
        if (*month < 12) {
            (*month)++;
        } else {
            *month = 1;
            (*year)++;
        }
    }
}

int main() {
    int day, month, year;

    // Meminta pengguna memasukkan tanggal
    printf("Masukkan tanggal (format: dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Menambahkan satu hari
    addOneDay(&day, &month, &year);

    // Menampilkan tanggal setelah ditambahkan satu hari
    printf("Tanggal setelah ditambahkan satu hari: %d/%d/%d\n", day, month, year);

    return 0;
}