#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>

#define first(L) ((L).first)
#define info(P) (P)->info
#define next(P) (P)->next
#define jadwalp(P) (P)->jadwalp
#define nil nullptr

using namespace std;

struct penumpang {
    string nama;
    string nik;
    string jk;
    int usia;
};

struct jadwalPenerbangan {
    string kode;
    string jenis;
    string tanggal;
    string waktu;
    string asal;
    string tujuan;
    int kapasitas;
};

typedef penumpang infotypePenumpang;
typedef jadwalPenerbangan infotypeJadwal;
typedef struct elemenJadwal *adr_jadwalP;
typedef struct elemenPenumpang *adr_penumpangP;

struct elemenJadwal {
    infotypeJadwal info;
    adr_jadwalP next;
};

struct elemenPenumpang {
    infotypePenumpang info;
    adr_jadwalP jadwalp;
    adr_penumpangP next;
};

struct listPenumpang {
    adr_penumpangP first;
};

struct listJadwal {
    adr_jadwalP first;
};

void createListJadwal(listJadwal &LJ);
adr_jadwalP createElemenJadwal(infotypeJadwal x);
void insertLastJ(listJadwal &LJ, adr_jadwalP p);
void showJadwal(listJadwal LJ);
void deleteFirstJ(listJadwal &LJ, adr_jadwalP &p);
adr_jadwalP SearchJ(listJadwal LJ, string dari, string ke, string tanggal);

void createListPenumpang(listPenumpang &LP);
adr_penumpangP createElemenPenumpang(infotypePenumpang x);
void insertLastP(listPenumpang &LP, adr_penumpangP p);
void booking(listPenumpang &LP, infotypePenumpang x, listJadwal LJ, string dari, string ke, string tanggal);
void showPenumpang(listPenumpang LP);
void reschedule(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal);
void showAllListPenumpang(listJadwal LJ, listPenumpang LP, string kode);

#endif
