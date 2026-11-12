#include "queue_vaksinasi.h"

int main() {
    Queue Q;
    createQueue(Q);

    ElemQ* P1 = createElemQueue("John Doe", 65, "lansia", 1, 0);
    ElemQ* P2 = createElemQueue("Alice", 30, "tenaga kesehatan", 2, 5);
    ElemQ* P3 = createElemQueue("Bob", 25, "pekerja", 3, 10);
    ElemQ* P4 = createElemQueue("Charlie", 70, "pensiunan", 4, 15);
    ElemQ* P5 = createElemQueue("David", 28, "pekerja", 5, 20);

    enqueue(Q, P1);
    enqueue(Q, P2);
    enqueue(Q, P3);
    enqueue(Q, P4);
    enqueue(Q, P5);

    cout << "Isi antrean awal:" << endl;
    printInfo(Q);

    cout << "\nMelakukan pelayanan pada antrean:" << endl;
    serveQueue(Q);

    cout << "\nisi antrean setelah pelayanan:" << endl;
    printInfo(Q);

    ElemQ* P6 = createElemQueue("Edward", 22, "pekerja", 6, 30);
    enqueue(Q, P6);

    cout << "\nMengatur ulang antrean berdasarkan prioritas:" << endl;
    reassignQueue(Q);
    printInfo(Q);

    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam:" << endl;
    checkWaitingTime(Q, 150);
    printInfo(Q);

    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5:" << endl;
    emergencyHandle(Q, 5);
    printInfo(Q);

    cout << "\nMengupdate prioritas antrean setiap jam:" << endl;
    updatePriority(Q);
    printInfo(Q);

    cout << "\nMenghapus warga dengan nomor antrean 3:" << endl;
    ElemQ* removedElem = findAndRemove(Q, 3);
    if (removedElem) {
        cout << "Warga yang dihapus: " << info(removedElem).nama << endl;
        delete removedElem;
    }
    printInfo(Q);

    cout << "\nUkuran antrean saat ini: " << size(Q) << endl;

    return 0;
}
