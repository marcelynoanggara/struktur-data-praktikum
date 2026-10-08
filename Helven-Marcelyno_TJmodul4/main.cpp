#include "SLL.h"

int main() {
    List L;
    createList(L);
    adr P;
    string nama_produk;

    for (int i = 1; i <= 5; i++) {
        cout << "Masukkan nama produk ke-" << i << ": ";
        cin >> nama_produk;
        P = alokasi(nama_produk);
        insertLast(L, P);
    }
    cout << "Daftar produk saat ini adalah: ";
    show(L);
    cout << "\n\n";
    cout << "Masukkan nama produk yang dicari: ";
    cin >> nama_produk;

    if (first(L) == NULL) {
        cout << "Maaf, daftar produk kosong\n";
    } else {
        P = findInfo(L, nama_produk);
        if (P != NULL) {
            cout << "PRODUK DITEMUKAN PADA ALAMAT " << P << "\n";
        } else {
            cout << "MAAF PRODUK TIDAK DITEMUKAN\n";
        }
    }
    cout << "\n";
    cout << "Daftar awal produk: ";
    show(L);
    cout << "\n\n";

    string pilihan;
    while (first(L) != NULL) {
        cout << "Lokasi produk yang dihapus (depan/belakang)? ";
        cin >> pilihan;

        if (pilihan == "depan") {
            deleteFirst(L, P);
        } else if (pilihan == "belakang") {
            deleteLast(L, P);
        } else {
            cout << "Pilihan tidak valid, silakan ketik 'depan' atau 'belakang'.\n";
            continue;
        }

        cout << "Daftar setelah dihapus: ";
        show(L);
        cout << "\n\n";
    }

    cout << "SELESAI\n";

    return 0;
}
