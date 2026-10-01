#include "Province.h"
#include <iostream>

using namespace std;


// ======================================================
// PROCEDURE buatProvinsi
// ======================================================

void buatProvinsi(provinsi &prov)
{
    cout << "Masukkan nama provinsi : ";
    cin >> prov.nama;

    cout << "Masukkan ibu kota      : ";
    cin >> prov.ibuKota;

    prov.terbesar = "";
    prov.popTerbesar = 0;
    prov.nKab = 0;
    prov.nKota = 0;
}


// ======================================================
// PROCEDURE perbaharuiTerbesar
// ======================================================

void perbaharuiTerbesar(provinsi &prov, string daerah, int populasi)
{
    if (populasi > prov.popTerbesar)
    {
        prov.terbesar = daerah;
        prov.popTerbesar = populasi;
    }
}


// ======================================================
// PROCEDURE tambahDaerah
// ======================================================

void tambahDaerah(provinsi &prov, bool flag)
{
    string daerah;
    int populasi;

    cout << "Masukkan nama daerah : ";
    cin >> daerah;

    cout << "Masukkan populasi     : ";
    cin >> populasi;

    if (flag == true)
    {

        prov.kota[prov.nKota] = daerah;
        prov.nKota++;
    }
    else
    {
        prov.kabupaten[prov.nKab] = daerah;
        prov.nKab++;
    }

    perbaharuiTerbesar(prov, daerah, populasi);
}


// ======================================================
// FUNCTION terdaftar
// Menggunakan Sequential Search
// ======================================================

bool terdaftar(provinsi prov, string daerah, bool flag)
{
    int i;

    if (flag == true)
    {
        i = 0;

        while (i < prov.nKota)
        {
            if (prov.kota[i] == daerah)
            {
                return true;
            }

            i++;
        }
    }
    else
    {
        i = 0;

        while (i < prov.nKab)
        {
            if (prov.kabupaten[i] == daerah)
            {
                return true;
            }

            i++;
        }
    }

    return false;
}


// ======================================================
// PROCEDURE tampilProvinsi
// ======================================================

void tampilProvinsi(provinsi prov)
{
    cout << "Nama Provinsi: "
         << prov.nama
         << " ("
         << prov.ibuKota
         << ")"
         << endl;

    cout << "Daerah Terbesar adalah "
         << prov.terbesar
         << " dari "
         << prov.nKota + prov.nKab
         << " Kota dan Kabupaten"
         << endl;

    cout << endl;
}
