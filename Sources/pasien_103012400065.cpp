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
     if (L.firstC == NULL) {
        L.firstC = P;
    } else {
        Q = L.firstC;
        while (Q->nextC != NULL) {
            Q = Q->nextC;
        }
        Q->nextC = P;
    }
}

void findChild(ListChild L, int ID){
    addressC P = L.firstC;
    bool ketemu = false;

    while (P != NULL) {
        if (P->info.ID == ID) {
            cout << "=== Data Pasien Ditemukan ===\n";
            cout << "Nama Pasien      : " << P->info.nama << endl;
            cout << "Umur             : " << P->info.umur << " tahun" << endl;
            cout << "Penyakit         : " << P->info.penyakit << endl;
            cout << "Poli Tujuan      : " << P->info.poliTujuan << endl;
            cout << "Tgl. Kunjungan   : " << P->info.tanggalKunjungan << endl;
            cout << "Nomor Antrian    : " << P->info.nomorAntrian << endl;
            cout << "Prioritas        : " << P->info.prioritas << endl;   
            ketemu = true;
            break;
        }
        P = P->nextC;
    }

    if (!ketemu){
        cout<<"ID Pasien Tidak Ditemukan\n";
    }
}

void deleteLastChild(ListChild &L, addressC &P){
     if (L.firstC == NULL) {
        P = NULL;  
    } 
    else if (L.firstC->nextC == NULL) {
        P = L.firstC;
        L.firstC = NULL;
    } 
    else {
        addressC Q = L.firstC;
        while (Q->nextC->nextC != NULL) {
            Q = Q->nextC;
        }
        P = Q->nextC;
        Q->nextC = NULL;
    }
}


void printInfoChild(ListChild L){
     addressC P = L.firstC;
    if (P == NULL) {
        cout << "Tidak ada pasien." << endl;
        return;
    }

    while (P != NULL) {
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

void searchByPenyakit(ListChild L, string penyakit){
addressC P = L.firstC;
    bool ketemu = false;

    while (P != NULL) {
        if (P->info.penyakit == penyakit) {
            if (!ketemu) {
                cout << "\n=== Hasil Pencarian Pasien dengan Penyakit: " << penyakit << " ===\n";
            }
            ketemu = true;

            cout << "Nama: " << P->info.nama << endl;
            cout << "Umur: " << P->info.umur << endl;
            cout << "ID: " << P->info.ID << endl;
            cout << "Poli Tujuan: " << P->info.poliTujuan << endl;
            cout << "Tanggal Kunjungan: " << P->info.tanggalKunjungan << endl;
            cout << "Nomor Antrian: " << P->info.nomorAntrian << endl;
            cout << "Prioritas: " << P->info.prioritas << endl;
            cout << "---------------------------------------\n";
        }
        P = P->nextC;
    }

    if (!ketemu) {
        cout << "Tidak ada pasien dengan penyakit \"" << penyakit << "\".\n";
    }
}

int countPasienPerPoli(ListChild L, string poliName){
    addressC P = L.firstC;
    int count = 0;

    while (P != NULL) {
        if (P->info.poliTujuan == poliName) {
            count++;
        }
        P = P->nextC;
    }

    return count;
}