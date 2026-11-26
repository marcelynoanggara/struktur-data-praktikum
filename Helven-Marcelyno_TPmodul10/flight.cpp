#include "flight.h"

void createListJadwal(ListJadwal &L) {
    first(L) = nil;
}

adr_jadwalP createElemenJadwal(infotype X) {
    adr_jadwalP P = new elemenJadwal;
    info(P) = X;
    next(P) = nil;
    return P;
}

void InsertLastJ(ListJadwal &L, adr_jadwalP P) {
    if (first(L) == nil) {
        first(L) = P;
    } else {
        adr_jadwalP Q = first(L);
        while (next(Q) != nil) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void ShowJadwal(ListJadwal L) {
    if (first(L) == nil) {
        cout << "List jadwal kosong." << endl;
        return;
    }
    adr_jadwalP P = first(L);
    while (P != nil) {
        cout << info(P).Kode << " | "
             << info(P).Jenis << " | "
             << info(P).Tanggal << " | "
             << info(P).Waktu << " | "
             << info(P).Asal << " | "
             << info(P).Tujuan << " | "
             << info(P).Kapasitas << endl;
        P = next(P);
    }
}

void DeleteFirstJ(ListJadwal &L, adr_jadwalP &P) {
    if (first(L) == nil) {
        P = nil;
    } else if (next(first(L)) == nil) {
        P = first(L);
        first(L) = nil;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = nil;
    }
}

adr_jadwalP SearchJ(ListJadwal L, string dari, string ke, string tanggal) {
    adr_jadwalP P = first(L);
    while (P != nil) {
        if (info(P).Asal == dari && info(P).Tujuan == ke && info(P).Tanggal == tanggal) {
            return P;
        }
        P = next(P);
    }
    return nil;
}
