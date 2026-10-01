#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>
using namespace std;

struct provinsi {
    string nama;
    string ibuKota;
    string terbesar;
    int popTerbesar;

    string kabupaten[20];
    string kota[20];

    int nKab;
    int nKota;
};

void buatProvinsi(provinsi &prov);

void tambahDaerah(provinsi &prov, bool flag);

void perbaharuiTerbesar(provinsi &prov, string daerah, int populasi);

bool terdaftar(provinsi prov, string daerah, bool flag);

void tampilProvinsi(provinsi prov);

#endif
