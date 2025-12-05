#include "Pasien.h"

void createListChild(ListChild &L) {
    L.firstC = nullptr;
}

void insertFirstChild(ListChild &L, addressC P) {
    if (isEmptyChild(L)) {
        L.firstC = P;
    } else {
        P->nextC = L.firstC;
        L.firstC = P;
    }
}

void insertAfterChild(ListChild &L, addressC P, addressC Prec) {
    if (Prec != nullptr) {
        P->nextC = Prec->nextC;
        Prec->nextC = P;
    }
}

void deleteFirstChild(ListChild &L, addressC &P) {
    if (!isEmptyChild(L)) {
        P = L.firstC;
        L.firstC = L.firstC->nextC;
        P->nextC = nullptr;
    }
}

void deleteAfterChild(ListChild &L, addressC &P, addressC Prec) {
    if (Prec != nullptr && Prec->nextC != nullptr) {
        P = Prec->nextC;
        Prec->nextC = P->nextC;
        P->nextC = nullptr;
    }
}

bool isEmptyChild(ListChild L) {
    return L.firstC == nullptr;
}

void sortByUmur(ListChild &L) {
    bool swapped;
    dataPasien temp;
    addressC current;
    if (isEmptyChild(L) || L.firstC->nextC == nullptr) {
        cout << "List Kosong" << endl; 
    }

    do {
        swapped = false;
        current = L.firstC;
        while (current->nextC != nullptr) {
            if (current->info.umur > current->nextC->info.umur) {
                temp = current->info;
                current->info = current->nextC->info;
                current->nextC->info = temp;
                swapped = true;
            }
            current = current->nextC;
        }
    } while (swapped);
}
