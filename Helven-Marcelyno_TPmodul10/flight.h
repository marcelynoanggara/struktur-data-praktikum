#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>

#define first(L) ((L).First)
#define info(P) (P)->info
#define next(P) (P)->next
#define nil nullptr

using namespace std;

struct jadwalPenerbangan {
    string Kode;
    string Jenis;
    string Tanggal;
    string Waktu;
    string Asal;
    string Tujuan;
    int Kapasitas;
};

typedef jadwalPenerbangan infotype;
typedef struct elemenJadwal *adr_jadwalP;

struct elemenJadwal {
    infotype info;
    adr_jadwalP next;
};

struct ListJadwal {
    adr_jadwalP First;
};

void createListJadwal(ListJadwal &L);
adr_jadwalP createElemenJadwal(infotype X);
void InsertLastJ(ListJadwal &L, adr_jadwalP P);
void ShowJadwal(ListJadwal L);
void DeleteFirstJ(ListJadwal &L, adr_jadwalP &P);
adr_jadwalP SearchJ(ListJadwal L, string dari, string ke, string tanggal);

#endif
