#include "stack_character.h"

// Membuat stack baru dengan Top = 0 (Stack kosong)[cite: 2]
void createStack(stack &S) {
    S.top = 0; // Menginisialisasi nilai top dengan 0[cite: 2]
}

// Mengecek apakah stack kosong[cite: 2]
bool isEmpty(stack S) {
    // Jika Top(S) = 0, maka true, jika tidak maka false[cite: 3]
    return S.top == 0;
}

// Mengecek apakah stack sudah penuh[cite: 2]
bool isFull(stack S) {
    // Jika Top(S) mencapai MAXSTACK (10), maka true[cite: 3]
    return S.top == MAXSTACK;
}

// Memasukkan elemen baru ke dalam stack[cite: 2]
void push(stack &S, infotype xpush) {
    // Mengecek apakah stack belum penuh[cite: 3]
    if (isFull(S) == false) {
        S.top = S.top + 1;            // Menaikkan nilai top sebanyak 1[cite: 3]
        S.info[S.top - 1] = xpush;    // Memasukkan data ke array (dikurangi 1 karena C++ index mulai dari 0)
    } else {
        cout << "Stack penuh" << endl; // Pesan jika stack sudah mencapai MAXSTACK[cite: 3]
    }
}

// Mengeluarkan elemen teratas dari stack[cite: 2]
void pop(stack &S, infotype &xpop) {
    // Mengecek apakah stack tidak kosong[cite: 4]
    if (isEmpty(S) == false) {
        xpop = S.info[S.top - 1]; // Menyimpan nilai elemen paling atas ke xpop[cite: 4]
        S.top = S.top - 1;        // Menurunkan nilai top sebanyak 1[cite: 4]
    } else {
        cout << "Stack kosong" << endl; // Pesan jika stack kosong tidak bisa di-pop[cite: 4]
    }
}

// Menampilkan seluruh elemen stack dari atas ke bawah[cite: 2]
void printInfo(stack S) {
    if (isEmpty(S) == false) {
        // Melakukan perulangan dari elemen paling atas ke elemen paling bawah (1)[cite: 4]
        for (int i = S.top; i >= 1; i--) {
            cout << S.info[i - 1] << " "; // Print elemen (dikurangi 1 menyesuaikan index C++)
        }
        cout << endl;
    } else {
        cout << "Stack kosong" << endl; //[cite: 4]
    }
}

// ----------------------------------------------------
// IMPLEMENTASI FUNGSI TAMBAHAN
// ----------------------------------------------------

// Mengurutkan isi stack dari kecil ke besar (Ascending)[cite: 4]
void ascending(stack &S) {
    // Menggunakan algoritma Bubble Sort sederhana pada array Stack
    for (int i = 0; i < S.top - 1; i++) {
        for (int j = 0; j < S.top - i - 1; j++) {
            if (S.info[j] > S.info[j + 1]) {
                // Proses menukar (swap) data jika elemen sebelumnya lebih besar
                infotype temp = S.info[j];
                S.info[j] = S.info[j + 1];
                S.info[j + 1] = temp;
            }
        }
    }
}

// Mengurutkan isi stack dari besar ke kecil (Descending)[cite: 4]
void descending(stack &S) {
    // Menggunakan algoritma Bubble Sort sederhana
    for (int i = 0; i < S.top - 1; i++) {
        for (int j = 0; j < S.top - i - 1; j++) {
            if (S.info[j] < S.info[j + 1]) {
                // Proses menukar (swap) data jika elemen sebelumnya lebih kecil
                infotype temp = S.info[j];
                S.info[j] = S.info[j + 1];
                S.info[j + 1] = temp;
            }
        }
    }
}

// Menerima input string dan memasukkan tiap karakternya ke stack[cite: 4]
void stringToStack(stack &S, const string &str) {
    // Melakukan perulangan (looping) untuk setiap karakter dalam string
    for (int i = 0; i < str.length(); i++) {
        if (!isFull(S)) {
            push(S, str[i]); // Memasukkan karakter ke stack jika belum penuh
        } else {
            cout << "Stack penuh, sebagian string tidak masuk." << endl;
            break; // Hentikan loop jika stack penuh
        }
    }
}

// Membalikkan urutan isi stack dari atas ke bawah atau sebaliknya[cite: 5]
void reverseStack(stack &S) {
    int start = 0;             // Indeks paling bawah stack
    int end = S.top - 1;       // Indeks paling atas stack

    // Menukar elemen ujung ke ujung hingga saling bertemu di tengah
    while (start < end) {
        infotype temp = S.info[start];
        S.info[start] = S.info[end];
        S.info[end] = temp;
        start++;
        end--;
    }
}
