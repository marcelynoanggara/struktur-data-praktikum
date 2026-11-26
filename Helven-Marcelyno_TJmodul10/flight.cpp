
#include "flight.h"

void createListJadwal(listJadwal &LJ) {
    first(LJ) = nil;
}

adr_jadwalP createElemenJadwal(infotypeJadwal x) {
    adr_jadwalP p = new elemenJadwal;
    info(p) = x;
    next(p) = nil;
    return p;
}

void insertLastJ(listJadwal &LJ, adr_jadwalP p) {
    if (first(LJ) == nil) {
        first(LJ) = p;
    } else {
        adr_jadwalP q = first(LJ);
        while (next(q) != nil) {
            q = next(q);
        }
        next(q) = p;
    }
}

void showJadwal(listJadwal LJ) {
    cout << "=======JADWAL=================" << endl;
    if (first(LJ) == nil) {
        cout << "Jadwal kosong." << endl;
    } else {
        adr_jadwalP p = first(LJ);
        while (p != nil) {
            cout << "Kode: " << info(p).kode << endl;
            cout << "Jenis: " << info(p).jenis << endl;
            cout << "Tanggal: " << info(p).tanggal << endl;
            cout << "Waktu: " << info(p).waktu << endl;
            cout << "Asal: " << info(p).asal << endl;
            cout << "Tujuan: " << info(p).tujuan << endl;
            cout << "Kapasitas: " << info(p).kapasitas << endl;
            p = next(p);
        }
    }
    cout << "==============================" << endl;
}

void deleteFirstJ(listJadwal &LJ, adr_jadwalP &p) {
    if (first(LJ) == nil) {
        p = nil;
    } else if (next(first(LJ)) == nil) {
        p = first(LJ);
        first(LJ) = nil;
    } else {
        p = first(LJ);
        first(LJ) = next(p);
        next(p) = nil;
    }
}

adr_jadwalP SearchJ(listJadwal LJ, string dari, string ke, string tanggal) {
    adr_jadwalP p = first(LJ);
    while (p != nil) {
        if (info(p).asal == dari && info(p).tujuan == ke && info(p).tanggal == tanggal) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void createListPenumpang(listPenumpang &LP) {
    first(LP) = nil;
}

adr_penumpangP createElemenPenumpang(infotypePenumpang x) {
    adr_penumpangP p = new elemenPenumpang;
    info(p) = x;
    jadwalp(p) = nil;
    next(p) = nil;
    return p;
}

void insertLastP(listPenumpang &LP, adr_penumpangP p) {
    if (first(LP) == nil) {
        first(LP) = p;
    } else {
        adr_penumpangP q = first(LP);
        while (next(q) != nil) {
            q = next(q);
        }
        next(q) = p;
    }
}

void booking(listPenumpang &LP, infotypePenumpang x, listJadwal LJ, string dari, string ke, string tanggal) {
    adr_jadwalP j = SearchJ(LJ, dari, ke, tanggal);
    if (j != nil) {
        adr_penumpangP p = createElemenPenumpang(x);
        jadwalp(p) = j;
        insertLastP(LP, p);
    } else {
        cout << "Jadwal penerbangan tidak ditemukan." << endl;
    }
}

void showPenumpang(listPenumpang LP) {
    cout << "=============PENUMPANG=================" << endl;
    if (first(LP) == nil) {
        cout << "Data penumpang kosong." << endl;
    } else {
        adr_penumpangP p = first(LP);
        while (p != nil) {
            cout << "Nama: " << info(p).nama << endl;
            cout << "NIK: " << info(p).nik << endl;
            cout << "Jenis Kelamin: " << info(p).jk << endl;
            cout << "Usia: " << info(p).usia << endl;
            if (jadwalp(p) != nil) {
                cout << "Kode: " << info(jadwalp(p)).kode << endl;
            } else {
                cout << "Kode: -" << endl;
            }
            p = next(p);
        }
    }
    cout << "==========================================" << endl;
}

void reschedule(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal) {
    adr_penumpangP p = first(LP);
    while (p != nil && info(p).nik != NIK) {
        p = next(p);
    }
    if (p == nil) {
        cout << "Penumpang dengan NIK " << NIK << " tidak ditemukan." << endl;
        return;
    }
    adr_jadwalP j = SearchJ(LJ, newDari, newKe, newTanggal);
    if (j != nil) {
        jadwalp(p) = j;
    } else {
        cout << "Jadwal baru tidak tersedia, reschedule dibatalkan." << endl;
    }
}

void showAllListPenumpang(listJadwal LJ, listPenumpang LP, string kode) {
    adr_jadwalP j = first(LJ);
    bool found = false;
    while (j != nil && !found) {
        if (info(j).kode == kode) {
            found = true;
        } else {
            j = next(j);
        }
    }
    cout << "=================PENUMPANG=================" << endl;
    if (!found) {
        cout << "Kode penerbangan tidak ditemukan." << endl;
    } else {
        adr_penumpangP p = first(LP);
        int total = 0;
        while (p != nil) {
            if (jadwalp(p) != nil && info(jadwalp(p)).kode == kode) {
                cout << "Nama: " << info(p).nama << endl;
                cout << "NIK: " << info(p).nik << endl;
                total++;
            }
            p = next(p);
        }
        cout << "Total Penumpang : " << total << endl;
    }
    cout << "===========================================" << endl;
}
