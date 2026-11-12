#include "queue_vaksinasi.h"

void createQueue(Queue &Q) {
    head(Q) = nill;
    tail(Q) = nill;
}

bool isEmpty(Queue Q) {
    return head(Q) == nill;
}

ElemQ* createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean, int waktu_daftar) {
    ElemQ *P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    info(P).waktu_daftar = waktu_daftar;
    next(P) = nill;
    return P;
}

void enqueue(Queue &Q, ElemQ *P) {
    if (isEmpty(Q)) {
        head(Q) = P;
        tail(Q) = P;
    } else if (info(P).prioritas) {
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

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Antrean kosong." << endl;
    } else {
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
}

void serveQueue(Queue &Q) {
    int count = 0;
    ElemQ *P;
    while (!isEmpty(Q) && count < 100) {
        dequeue(Q, P);
        if (P != nill) {
            cout << "Melayani warga:" << endl;
            cout << "Nama: " << info(P).nama << endl;
            cout << "Usia: " << info(P).usia << endl;
            cout << "Pekerjaan: " << info(P).pekerjaan << endl;
            cout << "Prioritas: " << (info(P).prioritas ? "Ya" : "Tidak") << endl;
            cout << "Vaksinasi berhasil." << endl;
            delete P;
            count++;
        }
    }
    if (count == 100 && !isEmpty(Q)) {
        cout << "Kapasitas telah penuh. Warga yang belum terlayani diminta kembali besok." << endl;
    }
}

void reassignQueue(Queue &Q) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P;
    while (!isEmpty(Q)) {
        dequeue(Q, P);
        next(P) = nill;
        info(P).prioritas = (info(P).usia >= 60 || info(P).pekerjaan == "tenaga kesehatan");
        enqueue(tempQ, P);
    }
    Q = tempQ;
}

void checkWaitingTime(Queue &Q, int waktu_sekarang) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P;
    while (!isEmpty(Q)) {
        dequeue(Q, P);
        next(P) = nill;
        if ((waktu_sekarang - info(P).waktu_daftar) >= 120) {
            info(P).prioritas = true;
        }
        enqueue(tempQ, P);
    }
    Q = tempQ;
}

void emergencyHandle(Queue &Q, int nomor_antrean) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P;
    ElemQ *darurat = nill;
    while (!isEmpty(Q)) {
        dequeue(Q, P);
        next(P) = nill;
        if (info(P).nomor_antrean == nomor_antrean && darurat == nill) {
            darurat = P;
            info(darurat).kondisi_darurat = true;
            info(darurat).prioritas = true;
        } else {
            enqueue(tempQ, P);
        }
    }
    Queue finalQ;
    createQueue(finalQ);
    if (darurat != nill) {
        enqueue(finalQ, darurat);
    } else {
        cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan." << endl;
    }
    while (!isEmpty(tempQ)) {
        dequeue(tempQ, P);
        next(P) = nill;
        enqueue(finalQ, P);
    }
    Q = finalQ;
}

void updatePriority(Queue &Q) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P;
    while (!isEmpty(Q)) {
        dequeue(Q, P);
        next(P) = nill;
        enqueue(tempQ, P);
    }
    Queue finalQ;
    createQueue(finalQ);
    Queue sisaQ;
    createQueue(sisaQ);
    while (!isEmpty(tempQ)) {
        dequeue(tempQ, P);
        next(P) = nill;
        if (info(P).kondisi_darurat) {
            enqueue(finalQ, P);
        } else {
            enqueue(sisaQ, P);
        }
    }
    while (!isEmpty(sisaQ)) {
        dequeue(sisaQ, P);
        next(P) = nill;
        enqueue(finalQ, P);
    }
    Q = finalQ;
}

ElemQ* findAndRemove(Queue &Q, int nomor_antrean) {
    Queue tempQ;
    createQueue(tempQ);
    ElemQ *P;
    ElemQ *found = nill;
    while (!isEmpty(Q)) {
        dequeue(Q, P);
        next(P) = nill;
        if (info(P).nomor_antrean == nomor_antrean && found == nill) {
            found = P;
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
