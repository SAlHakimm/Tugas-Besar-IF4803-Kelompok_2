#include "Poli.h"

addressP createElementParent(infotypeP x) {
    addressP P = new elmenP;
    P->infoP = x;
    P->next = nullptr;
    P->prev = nullptr;
    P->firstChild = nullptr;
    return P;
}

void insertLastParent(ListParent &L, addressP P) {
    if (isEmptyParent(L)) {
        L.first = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

addressP findParent(ListParent L, int IDPoli) {
    addressP P = L.first;
    while (P != nullptr) {
        if (P->infoP.IDPoli == IDPoli) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteLastParent(ListParent &L, addressP &P) {
    if (!isEmptyParent(L)) {
        P = L.Last;
        if (L.first == L.Last) {
            L.first = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void printInfoParent(ListParent L) {
    addressP P = L.first;
    addressC C;
    int count = 1;
    while (P != nullptr) {
        cout << "ID Poli: "<< P->infoP.IDPoli<<endl;
        cout << "Poli : " << P->infoP.namaPoli << endl;
        cout << "Dokter : " << P->infoP.namaDokter << endl;
        cout << "Kuota : " << P->infoP.kuotaPoli << endl;
        cout << "Jumlah Pasien : " << P->infoP.jumlahPasien << endl;
        C = P->firstChild;
        cout << "==============================================\n";
        cout << "Daftar Pasien: " << endl;
        while (C != nullptr) {
            cout << count << ". Pasien ID : " << C->info.ID << endl;
            cout << "Nama: " << C->info.nama << endl;
            cout << "Umur: " << C->info.umur << endl;
            cout << "Penyakit: " << C->info.penyakit << endl;
            C = C->nextC;
            count++;
            cout << "==============================================\n";
        }
        P = P->next;
    }
}

int hitungJumlahPasienPoli(ListParent L) {
    int totalPasien = 0;
    addressP P = L.first;
    while (P != nullptr) {
        totalPasien += P->infoP.jumlahPasien;
        P = P->next;
    }
    return totalPasien;
}

