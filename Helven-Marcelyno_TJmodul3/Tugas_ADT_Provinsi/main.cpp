#include <iostream>
#include "Province.h"

using namespace std;

int main()
{
    // ==================================================
    // DEKLARASI VARIABEL PROVINSI
    // ==================================================

    provinsi jawaBarat;
    provinsi jambi;
    provinsi sumateraBarat;
    provinsi yogyakarta;


    // ==================================================
    // MEMBUAT DATA PROVINSI
    // ==================================================

    cout << "========================================" << endl;
    cout << "        DATA PROVINSI INDONESIA" << endl;
    cout << "========================================" << endl;
    cout << endl;


    // ------------------------------------------
    // Jawa Barat
    // ------------------------------------------

    jawaBarat.nama = "Jawa_Barat";
    jawaBarat.ibuKota = "Bandung";
    jawaBarat.terbesar = "";
    jawaBarat.popTerbesar = 0;
    jawaBarat.nKab = 0;
    jawaBarat.nKota = 0;


    // ------------------------------------------
    // Jambi
    // ------------------------------------------

    jambi.nama = "Jambi";
    jambi.ibuKota = "Jambi";
    jambi.terbesar = "";
    jambi.popTerbesar = 0;
    jambi.nKab = 0;
    jambi.nKota = 0;


    // ------------------------------------------
    // Sumatera Barat
    // ------------------------------------------

    sumateraBarat.nama = "Sumatera_Barat";
    sumateraBarat.ibuKota = "Padang";
    sumateraBarat.terbesar = "";
    sumateraBarat.popTerbesar = 0;
    sumateraBarat.nKab = 0;
    sumateraBarat.nKota = 0;


    // ------------------------------------------
    // Yogyakarta
    // ------------------------------------------

    yogyakarta.nama = "Yogyakarta";
    yogyakarta.ibuKota = "Jogja";
    yogyakarta.terbesar = "";
    yogyakarta.popTerbesar = 0;
    yogyakarta.nKab = 0;
    yogyakarta.nKota = 0;


    // ==================================================
    // MENAMBAHKAN DATA JAWA BARAT
    // ==================================================

    // Kota Cimahi
    jawaBarat.kota[jawaBarat.nKota] = "Cimahi";
    jawaBarat.nKota++;
    perbaharuiTerbesar(jawaBarat, "Cimahi", 200);

    // Kab. Garut
    jawaBarat.kabupaten[jawaBarat.nKab] = "Garut";
    jawaBarat.nKab++;
    perbaharuiTerbesar(jawaBarat, "Garut", 210);

    // Kota Bandung
    jawaBarat.kota[jawaBarat.nKota] = "Bandung";
    jawaBarat.nKota++;
    perbaharuiTerbesar(jawaBarat, "Bandung", 500);

    // Kab. Sumedang
    jawaBarat.kabupaten[jawaBarat.nKab] = "Sumedang";
    jawaBarat.nKab++;
    perbaharuiTerbesar(jawaBarat, "Sumedang", 190);


    // ==================================================
    // MENAMBAHKAN DATA JAMBI
    // ==================================================

    // Kota Sungai Penuh
    jambi.kota[jambi.nKota] = "Sungai_Penuh";
    jambi.nKota++;
    perbaharuiTerbesar(jambi, "Sungai_Penuh", 150);

    // Kab. Batanghari
    jambi.kabupaten[jambi.nKab] = "Batanghari";
    jambi.nKab++;
    perbaharuiTerbesar(jambi, "Batanghari", 234);


    // ==================================================
    // MENAMBAHKAN DATA SUMATERA BARAT
    // ==================================================

    // Kota Solok
    sumateraBarat.kota[sumateraBarat.nKota] = "Solok";
    sumateraBarat.nKota++;
    perbaharuiTerbesar(sumateraBarat, "Solok", 120);

    // Kab. Agam
    sumateraBarat.kabupaten[sumateraBarat.nKab] = "Agam";
    sumateraBarat.nKab++;
    perbaharuiTerbesar(sumateraBarat, "Agam", 310);

    // Kab. Darmasraya
    sumateraBarat.kabupaten[sumateraBarat.nKab] = "Darmasraya";
    sumateraBarat.nKab++;
    perbaharuiTerbesar(sumateraBarat, "Darmasraya", 372);

    // Kab. Tanah Datar
    sumateraBarat.kabupaten[sumateraBarat.nKab] = "Tanah_Datar";
    sumateraBarat.nKab++;
    perbaharuiTerbesar(sumateraBarat, "Tanah_Datar", 250);

    // Kota Sawahlunto
    sumateraBarat.kota[sumateraBarat.nKota] = "Sawahlunto";
    sumateraBarat.nKota++;
    perbaharuiTerbesar(sumateraBarat, "Sawahlunto", 110);


    // ==================================================
    // MENAMBAHKAN DATA YOGYAKARTA
    // ==================================================

    // Kab. Sleman
    yogyakarta.kabupaten[yogyakarta.nKab] = "Sleman";
    yogyakarta.nKab++;
    perbaharuiTerbesar(yogyakarta, "Sleman", 317);

    // Kab. Bantul
    yogyakarta.kabupaten[yogyakarta.nKab] = "Bantul";
    yogyakarta.nKab++;
    perbaharuiTerbesar(yogyakarta, "Bantul", 290);

    // Kab. Kulon Progo
    yogyakarta.kabupaten[yogyakarta.nKab] = "Kulon_Progo";
    yogyakarta.nKab++;
    perbaharuiTerbesar(yogyakarta, "Kulon_Progo", 305);


    // ==================================================
    // PENGECEKAN TERDAFTAR
    // ==================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "       PENGECEKAN DATA DAERAH" << endl;
    cout << "========================================" << endl;
    cout << endl;


    // 1. Apakah Bandung adalah salah satu kota di Jambi?
    cout << "Apakah Bandung adalah salah satu kota di Jambi? ";

    if (terdaftar(jambi, "Bandung", true))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }


    // 2. Apakah Bandung adalah salah satu kabupaten di Jawa Barat?
    cout << "Apakah Bandung adalah salah satu kabupaten di Jawa Barat? ";

    if (terdaftar(jawaBarat, "Bandung", false))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }


    // 3. Apakah Bandung adalah salah satu kota di Yogyakarta?
    cout << "Apakah Bandung adalah salah satu kota di Yogyakarta? ";

    if (terdaftar(yogyakarta, "Bandung", true))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }


    // 4. Apakah Bandung adalah salah satu kota di Jawa Barat?
    cout << "Apakah Bandung adalah salah satu kota di Jawa Barat? ";

    if (terdaftar(jawaBarat, "Bandung", true))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }


    // ==================================================
    // MENAMPILKAN DATA PROVINSI
    // ==================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "          DATA PROVINSI" << endl;
    cout << "========================================" << endl;
    cout << endl;

    tampilProvinsi(jawaBarat);
    tampilProvinsi(jambi);
    tampilProvinsi(sumateraBarat);
    tampilProvinsi(yogyakarta);


    return 0;
}
