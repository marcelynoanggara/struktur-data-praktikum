#include "SLL.h"

int main() {
    List L;
    createNewList(L);
    int pilihan;

    do {
        cout << "\nMenu Restoran Pagi Sore:" << endl;
        cout << "1. Tambah data masakan" << endl;
        cout << "2. Tampilkan semua data masakan" << endl;
        cout << "3. Tampilkan semua data masakan yang masih tersedia" << endl;
        cout << "4. Tampilkan semua data masakan yang paling laku terjual (best seller)" << endl;
        cout << "5. Hapus semua data masakan yang sudah laku terjual" << endl;
        cout << "6. Transaksi pembelian masakan (Bonus)" << endl;
        cout << "0. Selesai" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int n;
                cout << "Masukkan jumlah data masakan : ";
                cin >> n;
                addNElementList(L, n);
                break;
            }
            case 2:
                showAllFood(L);
                break;
            case 3:
                showAvailableFood(L);
                break;
            case 4:
                showBestSeller(L);
                break;
            case 5:
                deleteAllSoldOut(L);
                break;
            case 6: {
                int no, porsi;
                cout << "Nomor Masakan yang dibeli : ";
                cin >> no;
                cout << "Jumlah porsi yang dibeli : ";
                cin >> porsi;
                transaction(L, no, porsi);
                break;
            }
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
