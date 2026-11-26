#include "flight.h"

int main() {
    listJadwal LJ;
    listPenumpang LP;
    infotypeJadwal dataJ;
    infotypePenumpang dataP;
    adr_jadwalP ptrJ;
    string dari, ke, tanggal, kodeCari, nikReschedule;

    createListJadwal(LJ);

    cout << "Input Penerbangan" << endl;
    for (int i = 1; i <= 4; i++) {
        cout << "Data ke-" << i << endl;
        cout << "Kode: ";
        getline(cin >> ws, dataJ.kode);
        cout << "Jenis: ";
        getline(cin >> ws, dataJ.jenis);
        cout << "Tanggal: ";
        getline(cin >> ws, dataJ.tanggal);
        cout << "Waktu: ";
        getline(cin >> ws, dataJ.waktu);
        cout << "Asal: ";
        getline(cin >> ws, dataJ.asal);
        cout << "Tujuan: ";
        getline(cin >> ws, dataJ.tujuan);
        cout << "Kapasitas: ";
        cin >> dataJ.kapasitas;

        ptrJ = createElemenJadwal(dataJ);
        insertLastJ(LJ, ptrJ);
    }

    showJadwal(LJ);

    createListPenumpang(LP);

    cout << "Input Jadwal" << endl;
    for (int i = 1; i <= 6; i++) {
        cout << "Data ke-" << i << endl;
        cout << "Nama: ";
        getline(cin >> ws, dataP.nama);
        cout << "NIK: ";
        getline(cin >> ws, dataP.nik);
        cout << "Jenis Kelamin: ";
        getline(cin >> ws, dataP.jk);
        cout << "Usia: ";
        cin >> dataP.usia;
        cout << "Asal Penerbangan: ";
        getline(cin >> ws, dari);
        cout << "Tujuan Penerbangan: ";
        getline(cin >> ws, ke);
        cout << "Tanggal Penerbangan: ";
        getline(cin >> ws, tanggal);

        booking(LP, dataP, LJ, dari, ke, tanggal);
    }

    showPenumpang(LP);

    cout << "Tampilkan Penumpang Berdasarkan Kode Penerbangan" << endl;
    cout << "Kode: ";
    getline(cin >> ws, kodeCari);
    showAllListPenumpang(LJ, LP, kodeCari);

    cout << "Reschedule" << endl;
    cout << "NIK: ";
    getline(cin >> ws, nikReschedule);
    cout << "Asal: ";
    getline(cin >> ws, dari);
    cout << "Tujuan: ";
    getline(cin >> ws, ke);
    cout << "Tanggal: ";
    getline(cin >> ws, tanggal);
    reschedule(LP, LJ, nikReschedule, dari, ke, tanggal);

    cout << "Tampilkan Penumpang Berdasarkan Kode Penerbangan" << endl;
    cout << "Kode: ";
    getline(cin >> ws, kodeCari);
    showAllListPenumpang(LJ, LP, kodeCari);

    return 0;
}
