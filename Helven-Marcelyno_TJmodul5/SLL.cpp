#include "SLL.h"

void createNewList(List &L) {
    L.first = NULL;
}

void insertLast(List &L, address p) {
    if (empty(L)) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void deleteFirst(List &L, address &p) {
    if (!empty(L)) {
        p = L.first;
        L.first = L.first->next;
        p->next = NULL;
    }
}

void deleteLast(List &L, address &p) {
    if (!empty(L)) {
        if (L.first->next == NULL) {
            p = L.first;
            L.first = NULL;
        } else {
            address q = L.first;
            while (q->next->next != NULL) {
                q = q->next;
            }
            p = q->next;
            q->next = NULL;
        }
    }
}

void deleteAfter(List &L, address prec, address &P) {
    if (prec != NULL && prec->next != NULL) {
        P = prec->next;
        prec->next = P->next;
        P->next = NULL;
    }
}

bool empty(List mList) {
    return mList.first == NULL;
}

infotype newMasakan(int no, string nama) {
    infotype m;
    m.nomor = no;
    m.nama = nama;
    m.sisaPorsi = S;
    return m;
}

address newElementList(infotype m) {
    address p = new ElmtMsk;
    p->info = m;
    p->next = NULL;
    return p;
}

void addNElementList(List &mList, int N) {
    for (int i = 0; i < N; i++) {
        int no;
        string nama;
        cout << "Nomor Masakan : ";
        cin >> no;
        cout << "Nama Masakan  : ";
        cin >> ws;
        getline(cin, nama);

        infotype m = newMasakan(no, nama);
        address p = newElementList(m);
        insertLast(mList, p);
    }
}

void showAllFood(List mList) {
    if (empty(mList)) {
        cout << "Data masakan kosong." << endl;
    } else {
        address p = mList.first;
        while (p != NULL) {
            cout << "No: " << p->info.nomor << " | Nama: " << p->info.nama << " | Sisa Porsi: " << p->info.sisaPorsi << endl;
            p = p->next;
        }
    }
}

void showAvailableFood(List mList) {
    if (empty(mList)) {
        cout << "Data masakan kosong." << endl;
    } else {
        address p = mList.first;
        bool found = false;
        while (p != NULL) {
            if (p->info.sisaPorsi > 0) {
                cout << "No: " << p->info.nomor << " | Nama: " << p->info.nama << " | Sisa Porsi: " << p->info.sisaPorsi << endl;
                found = true;
            }
            p = p->next;
        }
        if (!found) cout << "Tidak ada masakan yang tersedia." << endl;
    }
}

address findMinRemaining(List mList) {
    if (empty(mList)) return NULL;

    address p = mList.first;
    address minAdd = p;
    while (p != NULL) {
        if (p->info.sisaPorsi < minAdd->info.sisaPorsi) {
            minAdd = p;
        }
        p = p->next;
    }
    return minAdd;
}

void showBestSeller(List mList) {
    if (empty(mList)) {
        cout << "Data masakan kosong." << endl;
        return;
    }

    address minElement = findMinRemaining(mList);
    int minPorsi = minElement->info.sisaPorsi;

    cout << "=== Best Seller ===" << endl;
    address p = mList.first;
    while (p != NULL) {
        if (p->info.sisaPorsi == minPorsi) {
            cout << "No: " << p->info.nomor << " | Nama: " << p->info.nama << " | Terjual: " << (S - p->info.sisaPorsi) << " porsi" << endl;
        }
        p = p->next;
    }
}

void deleteAllSoldOut(List &mList) {
    if (empty(mList)) return;

    address p = mList.first;
    address prec = NULL;
    address temp;

    while (p != NULL) {
        if (p->info.sisaPorsi == 0) {
            if (p == mList.first) {
                deleteFirst(mList, temp);
                delete temp;
                p = mList.first;
            } else {
                deleteAfter(mList, prec, temp);
                delete temp;
                p = prec->next;
            }
        } else {
            prec = p;
            p = p->next;
        }
    }
    cout << "Pembersihan data sold out selesai." << endl;
}

void transaction(List &L, int noMasakan, int porsi) {
    address p = L.first;
    bool found = false;

    while (p != NULL && !found) {
        if (p->info.nomor == noMasakan) {
            found = true;
            if (p->info.sisaPorsi >= porsi) {
                p->info.sisaPorsi -= porsi;
                cout << "Transaksi berhasil. Sisa porsi sekarang: " << p->info.sisaPorsi << endl;
            } else {
                cout << "Transaksi gagal. Porsi tidak mencukupi." << endl;
            }
        }
        p = p->next;
    }
    if (!found) {
        cout << "Masakan dengan nomor " << noMasakan << " tidak ditemukan." << endl;
    }
}
