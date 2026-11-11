#ifndef QUEUE_VAKSINASI_H
#define QUEUE_VAKSINASI_H

#include <iostream>
#include <string>

using namespace std;

#define nill nullptr

// Definisi Struktur Data
struct Infotype {
    string nama;
    int usia;
    string pekerjaan;
    bool prioritas;
    int nomor_antrean;
    int waktu_daftar;
    bool kondisi_darurat;
};

struct ElemQ {
    Infotype info;
    ElemQ *next;
};

struct Queue {
    ElemQ *head;
    ElemQ *tail;
};

// Makro untuk mempermudah akses
#define info(P) (P)->info
#define next(P) (P)->next
#define head(Q) (Q).head
#define tail(Q) (Q).tail

// ==========================================
// FUNGSI & PROSEDUR PRIMITIF
// ==========================================

void createQueue(Queue &Q) {
    head(Q) = nill;
    tail(Q) = nill;
}

bool isEmpty(Queue Q) {
    return head(Q) == nill;
}

ElemQ* createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean) {
    ElemQ *P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    info(P).waktu_daftar = 0; // Default awal
    next(P) = nill;
    return P;
}

void enqueue(Queue &Q, ElemQ *P) {
    if (isEmpty(Q)) {
        head(Q) = P;
        tail(Q) = P;
    } else if (info(P).prioritas) {
        // Jika elemen baru adalah prioritas, masukkan setelah prioritas yang sudah ada
        if (!info(head(Q)).prioritas) {
            next(P) = head(Q);
            head(Q) = P;
        } else {
            ElemQ *temp = head(Q);
            while (next(temp) != nill && info(next(temp)).prioritas) {
                temp = next(temp);
            }
            next(P) = next(temp);
            next(temp) = P;
            if (next(P) == nill) {
                tail(Q) = P;
            }
        }
    } else {
        // Jika non-prioritas, ditaruh di paling belakang
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void dequeue(Queue &Q, ElemQ *&P) {
    if (isEmpty(Q)) {
        P = nill;
        cout << "Semua warga telah terlayani." << endl;
    } else {
        P = head(Q);
        head(Q) = next(head(Q));
        if (head(Q) == nill) {
            tail(Q) = nill;
        }
        next(P) = nill;
    }
}

ElemQ* front(Queue Q) {
    return head(Q);
}

ElemQ* back(Queue Q) {
    return tail(Q);
}

int size(Queue Q) {
    int count = 0;
    ElemQ *temp = head(Q);
    while (temp != nill) {
        count++;
        temp = next(temp);
    }
    return count;
}

// ==========================================
// FUNGSI & PROSEDUR NON-PRIMITIF
// ==========================================

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Antrean kosong." << endl;
        return;
    }
    cout << "Daftar Antrean:" << endl;
    ElemQ *temp = head(Q);
    while (temp != nill) {
        cout << "Nama: " << info(temp).nama << endl;
        cout << "Usia: " << info(temp).usia << endl;
        cout << "Pekerjaan: " << info(temp).pekerjaan << endl;
        cout << "Prioritas: " << (info(temp).prioritas ? "Ya" : "Tidak") << endl;
        cout << "Nomor Antrean: " << info(temp).nomor_antrean << endl;
        temp = next(temp);
    }
}

void serveQueue(Queue &Q) {
    int kapasitas = 0;
    ElemQ *P = nill;

    while (!isEmpty(Q) && kapasitas < 100) {
        dequeue(Q, P);
        if (P != nill) {
            cout << "Melayani warga:" << endl;
            cout << "Nama\t\t: " << info(P).nama << endl;
            cout << "Usia\t\t: " << info(P).usia << endl;
            cout << "Pekerjaan\t: " << info(P).pekerjaan << endl;
            cout << "Prioritas\t: " << (info(P).prioritas ? "Ya" : "Tidak") << endl;
            cout << "Vaksinasi berhasil.\n" << endl;
            delete P;
            kapasitas++;
        }
    }

    if (kapasitas == 100 && !isEmpty(Q)) {
        cout << "Kapasitas telah penuh. Warga yang belum terlayani diminta kembali besok." << endl;
    }
}

void reassignQueue(Queue &Q) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P = nill;

    while (!isEmpty(Q)) {
        dequeue(Q, P);
        // Memastikan status prioritas dihitung kembali sesuai kategori usia/pekerjaan
        info(P).prioritas = (info(P).usia >= 60 || info(P).pekerjaan == "tenaga kesehatan");
        enqueue(tempQ, P);
    }
    Q = tempQ;
}

void checkWaitingTime(Queue &Q, int waktu_sekarang) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P = nill;

    while (!isEmpty(Q)) {
        dequeue(Q, P);
        int waktu_tunggu = waktu_sekarang - info(P).waktu_daftar;
        if (waktu_tunggu > 120) {
            info(P).prioritas = true;
        }
        enqueue(tempQ, P);
    }
    Q = tempQ;
}

ElemQ* findAndRemove(Queue &Q, int nomor_antrean) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P = nill;
    ElemQ *found = nill;

    while (!isEmpty(Q)) {
        dequeue(Q, P);
        if (info(P).nomor_antrean == nomor_antrean && found == nill) {
            found = P; // Pisahkan elemen yang dicari, tidak dikembalikan ke tempQ
        } else {
            enqueue(tempQ, P);
        }
    }
    Q = tempQ;

    if (found == nill) {
        cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan dalam antrean." << endl;
    }
    return found;
}

void emergencyHandle(Queue &Q, int nomor_antrean) {
    ElemQ *P = findAndRemove(Q, nomor_antrean);
    if (P != nill) {
        info(P).kondisi_darurat = true;
        info(P).prioritas = true;

        // Memaksa elemen diletakkan di posisi paling depan queue
        if (isEmpty(Q)) {
            head(Q) = P;
            tail(Q) = P;
            next(P) = nill;
        } else {
            next(P) = head(Q);
            head(Q) = P;
        }
    } else {
        // Output mengikuti format modul saat elemen tak ditemukan
    }
}

void updatePriority(Queue &Q) {
    Queue tempQ, emergQ;
    createQueue(tempQ);
    createQueue(emergQ);
    ElemQ *P = nill;

    // Pisahkan elemen yang darurat dengan yang tidak
    while (!isEmpty(Q)) {
        dequeue(Q, P);
        if (info(P).kondisi_darurat) {
            enqueue(emergQ, P);
        } else {
            enqueue(tempQ, P);
        }
    }

    // Masukkan kembali mulai dari kondisi darurat, lalu sisanya
    // Fungsi primitive enqueue akan otomatis mengurutkan prioritas sisanya
    while (!isEmpty(emergQ)) {
        dequeue(emergQ, P);
        enqueue(Q, P);
    }
    while (!isEmpty(tempQ)) {
        dequeue(tempQ, P);
        enqueue(Q, P);
    }
}

#endif
