#include <iostream>
#include <string>
#include "stack_character.h"

using namespace std;

int main() {
    stack S1, S2, S3; //[cite: 6]
    infotype xpop;    //[cite: 6]

    // PENGUJIAN S1
    createStack(S1);  //[cite: 6]
    printInfo(S1);    //[cite: 6]
    push(S1, 'E');    //[cite: 6]
    printInfo(S1);    //[cite: 6]
    push(S1, 'T');    //[cite: 6]
    printInfo(S1);    //[cite: 6]
    push(S1, 'U');    //[cite: 6]
    printInfo(S1);    //[cite: 6]
    pop(S1, xpop);    //[cite: 6]
    printInfo(S1);    //[cite: 6]

    cout << endl << "Data diurutkan ascending:" << endl; //[cite: 6]
    ascending(S1); //[cite: 6]
    printInfo(S1); //[cite: 6]

    cout << endl << "Data diurutkan descending:" << endl; //[cite: 6]
    descending(S1); //[cite: 6]
    printInfo(S1);  //[cite: 6]

    // PENGUJIAN S2
    createStack(S2); //[cite: 6]
    string kalimat = "Hai kamu!!!"; //[cite: 6]
    cout << endl << "\'Hai kamu!!!\' di dalam stack:" << endl; //[cite: 6]
    stringToStack(S2, kalimat); //[cite: 6]
    printInfo(S2); //[cite: 6]

    cout << endl << "Data diurutkan ascending:" << endl; //[cite: 6]
    ascending(S2); //[cite: 6]
    printInfo(S2); //[cite: 6]

    cout << endl << "Data diurutkan descending:" << endl; //[cite: 6]
    descending(S2); //[cite: 6]
    printInfo(S2);  //[cite: 6]

    // PENGUJIAN S3
    createStack(S3); // Telah ditambahkan titik koma yang kurang di modul[cite: 6]
    cout << endl << "Membalik urutan elemen " << endl; //[cite: 6]
    string input; //[cite: 6]

    cout << "Masukkan string: "; //
    // Inputkan "IFLAB 2024/2025"[cite: 7]
    getline(cin, input); // Menggunakan getline untuk membaca string dengan spasi[cite: 7]
    stringToStack(S3, input); //[cite: 7]

    cout << endl << "Data sebelum dibalik:"; //[cite: 7]
    printInfo(S3); //[cite: 7]
    cout << endl;  //[cite: 7]

    reverseStack(S3); // Telah ditambahkan titik koma yang kurang di modul[cite: 7]
    cout << "Data setelah dibalik:"; //[cite: 7]
    printInfo(S3); //[cite: 7]
    cout << endl;  //[cite: 7]

    return 0; //[cite: 7]
}
