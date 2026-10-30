#ifndef STACK_CHARACTER_H_INCLUDED
#define STACK_CHARACTER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan konstanta batas maksimal stack sesuai modul
const int MAXSTACK = 10;
// Mendefinisikan tipe data elemen stack menjadi karakter (char)
typedef char infotype;

// Struktur dari stack[cite: 1]
struct stack {
    infotype info[MAXSTACK]; // Array untuk menyimpan elemen karakter[cite: 1]
    int top;                 // Indeks untuk menandai elemen paling atas stack[cite: 1]
};

// ==========================================
// Deklarasi Prosedur dan Fungsi Stack
// ==========================================
void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype xpush);
void pop(stack &S, infotype &xpop);
void printInfo(stack S);

// Deklarasi prosedur tambahan yang diminta di modul
void ascending(stack &S);
void descending(stack &S);
void stringToStack(stack &S, const string &str);
void reverseStack(stack &S);

#endif // STACK_CHARACTER_H_INCLUDED
