#include "dll_driver.h"

int main() {
    List L, listA, listB;
    createList(L);
    infotype data;
    address P;

    cout << "=== 1. INPUT 4 DATA DRIVER AWAL ===" << endl;
    for (int i = 1; i <= 4; i++) {
        cout << "Driver ke-" << i << endl;
        cout << "Nama Driver : ";
        getline(cin >> ws, data.nama);
        cout << "Rating      : ";
        cin >> data.rating;
        P = allocate(data);
        insertLast(L, P);
    }

    cout << "\n=== 2. DATA DRIVER DALAM LIST ===" << endl;
    printInfo(L);

    cout << "\n=== 3. MENGHAPUS 1 DATA PERTAMA ===" << endl;
    deleteFirst(L, P);
    if (P != nil) {
        cout << "Data dihapus : " << info(P).nama << " (" << fixed << setprecision(2) << info(P).rating << ")" << endl;
        delete P;
    }
    cout << "Data setelah penghapusan:" << endl;
    printInfo(L);

    cout << "\n=== 4. PROSES RESET DATA & RATA-RATA RATING ===" << endl;
    resetData(L);

    cout << "\n=== 5. INPUT 4 DATA DRIVER BARU ===" << endl;
    for (int i = 1; i <= 4; i++) {
        cout << "Driver ke-" << i << endl;
        cout << "Nama Driver : ";
        getline(cin >> ws, data.nama);
        cout << "Rating      : ";
        cin >> data.rating;
        P = allocate(data);
        insertLast(L, P);
    }
    cout << "\nData driver baru dalam list:" << endl;
    printInfo(L);

    cout << "\n=== 6. PROSES SPLIT BERDASARKAN RATING N ===" << endl;
    float N;
    do {
        cout << "Masukkan batas rating N (0.00 - 5.00): ";
        cin >> N;
    } while (N < 0.00 || N > 5.00);

    splitData(L, listA, listB, N);

    cout << "\nHasil List A (Rating < " << fixed << setprecision(2) << N << "):" << endl;
    printInfo(listA);

    cout << "\nHasil List B (Rating >= " << fixed << setprecision(2) << N << "):" << endl;
    printInfo(listB);

    cout << "\nStatus List Awal setelah Split:" << endl;
    printInfo(L);

    return 0;
}
