#include "DLL.h"

int main() {
    List L1, L2, L3;
    infotype data;
    address P;

    createList(L1);
    createList(L2);

    cout << "=== MENGISI LIST 1 ===\n";
    data.namaBand = "Foster The People";
    data.judulLagu = "Imagination";
    P = createNewElmt(data);
    insertFirst(L1, P);

    data.namaBand = "The Corrs";
    data.judulLagu = "Radio";
    P = createNewElmt(data);
    insertLast(L1, P);

    cout << "Isi List 1:\n";
    printList(L1);

    cout << "=== MENGISI LIST 2 ===\n";
    data.namaBand = "Maroon 5";
    data.judulLagu = "Sugar";
    P = createNewElmt(data);
    insertFirst(L2, P);

    data.namaBand = "Coldplay";
    data.judulLagu = "Yellow";
    P = createNewElmt(data);
    insertLast(L2, P);

    cout << "Isi List 2:\n";
    printList(L2);

    cout << "=== CONCAT LIST 1 & LIST 2 KE LIST 3 ===\n";
    concat(L1, L2, L3);
    cout << "Isi List 3 (Hasil Gabungan):\n";
    printList(L3);

    string laguDihapus;
    cout << "Masukkan Judul Lagu yang ingin dihapus dari List 3: ";
    getline(cin, laguDihapus);

    removeLagu(laguDihapus, L3);

    cout << "\n=== ISI LIST 3 SETELAH PENGHAPUSAN ===\n";
    printList(L3);

    return 0;
}
