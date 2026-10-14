#include "list.h"

int main() {
    List L;
    createList_108092500012(L);
    int menu;
    char kembali;

    do {
        cout << "======MENU=======\n";
        cout << "1. Menambah N data baru\n";
        cout << "2. Menampilkan semua data\n";
        cout << "3. Cari alamat nilai terkecil (findMin)\n";
        cout << "4. Sisip data di tengah (insertMiddle)\n";
        cout << "0. Exit\n";
        cout << "Masukkan menu: ";
        cin >> menu;

        if (menu == 1) {
            int n, data;
            cout << "Jumlah data yang akan ditambahkan: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Masukkan data baru: ";
                cin >> data;
                address P = allocate_108092500012(data);
                insertLast_108092500012(L, P);
            }
        } else if (menu == 2) {
            cout << "Data list saat ini: ";
            showAllData_108092500012(L);
        } else if (menu == 3) {
            address minData = findMin_108092500012(L);
            if (minData != nullptr) {
                cout << "Alamat nilai terkecil: " << minData << "\n";
                cout << "Nilai terkecilnya adalah: " << minData->info << "\n";
            } else {
                cout << "List kosong.\n";
            }
        } else if (menu == 4) {
            int data;
            cout << "Masukkan data bilangan ke tengah: ";
            cin >> data;
            insertMiddle_108092500012(L, data);
            cout << "Data berhasil disisipkan.\n";
        } else if (menu == 0) {
            cout << "ANDA TELAH KELUAR DARI PROGRAM\n";
            break;
        } else {
            cout << "Pilihan tidak valid.\n";
        }

        if (menu != 0) {
            cout << "Kembali ke menu utama? (Y/N): ";
            cin >> kembali;
            if (kembali == 'N' || kembali == 'n') {
                cout << "ANDA TELAH KELUAR DARI PROGRAM\n";
                break;
            }
            cout << "\n";
        }
    } while (menu != 0);

    return 0;
}
