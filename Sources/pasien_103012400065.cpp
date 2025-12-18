#include <iostream>
#include "Pasien.h"
using namespace std;

addressC createElementChild(dataPasien x){
    addressC P;
    P = new elmPasien;
    P->info = x;
    P->nextC = nullptr;
    return P;
}

void insertLastChild(ListChild &L, addressC P){
    addressC Q;
     if (L.firstC == nullptr) {
        L.firstC = P;
    } else {
        Q = L.firstC;
        while (Q->nextC != nullptr) {
            Q = Q->nextC;
        }
        Q->nextC = P;
    }
}

addressC findChild(ListChild L, int ID) {
    addressC P = L.firstC;
    while (P != nullptr) {
        if (P->info.ID == ID) {
            return P;
        }
        P = P->nextC;
    }
    return nullptr;
}


void deleteLastChild(ListChild &L, addressC &P){
     if (L.firstC == nullptr) {
        P = nullptr;
    }
    else if (L.firstC->nextC == nullptr) {
        P = L.firstC;
        L.firstC = nullptr;
    }
    else {
        addressC Q = L.firstC;
        while (Q->nextC->nextC != nullptr) {
            Q = Q->nextC;
        }
        P = Q->nextC;
        Q->nextC = nullptr;
    }
}


void printInfoChild(addressC first){
   addressC P = first;

    if (P == nullptr) {
        cout << "Tidak ada pasien." << endl;
        return;
    }

    while (P != nullptr) {
        cout << "Nama: " << P->info.nama << endl;
        cout << "Umur: " << P->info.umur << endl;
        cout << "Penyakit: " << P->info.penyakit << endl;
        cout << "ID: " << P->info.ID << endl;
        cout << "Poli Tujuan: " << P->info.poliTujuan << endl;
        cout << "Tanggal Kunjungan: " << P->info.tanggalKunjungan << endl;
        cout << "Nomor Antrian: " << P->info.nomorAntrian << endl;
        cout << "Prioritas: " << P->info.prioritas << endl;
        cout << "------------------------" << endl;
        P = P->nextC;
    }
}


