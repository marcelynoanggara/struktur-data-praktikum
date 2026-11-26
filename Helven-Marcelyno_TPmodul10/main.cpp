#include "flight.h"

int main() {
    ListJadwal L;
    int n;
    infotype data;
    adr_jadwalP P;

    createListJadwal(L);

    cout << "Masukkan jumlah jadwal penerbangan (n): ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nData Jadwal ke-" << i << endl;
        cout << "Kode      : ";
        getline(cin >> ws, data.Kode);
        cout << "Jenis     : ";
        getline(cin >> ws, data.Jenis);
        cout << "Tanggal   : ";
        getline(cin >> ws, data.Tanggal);
        cout << "Waktu     : ";
        getline(cin >> ws, data.Waktu);
        cout << "Asal      : ";
        getline(cin >> ws, data.Asal);
        cout << "Tujuan    : ";
        getline(cin >> ws, data.Tujuan);
        cout << "Kapasitas : ";
        cin >> data.Kapasitas;

        P = createElemenJadwal(data);
        InsertLastJ(L, P);
    }

    cout << "\n=== DAFTAR JADWAL PENERBANGAN ===" << endl;
    ShowJadwal(L);

    cout << "\n=== MENGHAPUS JADWAL PERTAMA ===" << endl;
    DeleteFirstJ(L, P);
    if (P != nil) {
        cout << "Jadwal dihapus: " << info(P).Kode << " (" << info(P).Asal << " -> " << info(P).Tujuan << ")" << endl;
        delete P;
    }

    cout << "\n=== DAFTAR JADWAL SETELAH PENGHAPUSAN ===" << endl;
    ShowJadwal(L);

    cout << "\n=== PENCARIAN JADWAL (Surabaya -> Malang, 9 Desember 2022) ===" << endl;
    adr_jadwalP hasil = SearchJ(L, "Surabaya (SUB)", "Malang (MLG)", "9 Desember 2022");
    if (hasil != nil) {
        cout << "Jadwal ditemukan: "
             << info(hasil).Kode << " | "
             << info(hasil).Jenis << " | "
             << info(hasil).Tanggal << " | "
             << info(hasil).Waktu << " | "
             << info(hasil).Asal << " -> "
             << info(hasil).Tujuan << " | Kapasitas: "
             << info(hasil).Kapasitas << endl;
    } else {
        cout << "Jadwal tidak ditemukan." << endl;
    }

    return 0;
}
