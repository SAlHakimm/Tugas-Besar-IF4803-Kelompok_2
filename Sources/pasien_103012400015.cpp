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

void riwayatPenyakit(addressC firstChild, string namaPasien){
    addressC P = firstChild;
    bool ketemu = false;
    while (P != nullptr) {
        if (P->info.nama == namaPasien) {
            cout << "=== RIWAYAT PENYAKIT PASIEN ===\n";
            cout << "Nama            : " << P->info.nama << endl;
            cout << "Umur            : " << P->info.umur << endl;
            cout << "Penyakit        : " << P->info.penyakit << endl;
            cout << "ID              : " << P->info.ID << endl;
            cout << "Poli Tujuan     : " << P->info.poliTujuan << endl;
            cout << "Tanggal Kunjungan: " << P->info.tanggalKunjungan << endl;
            cout << "Nomor Antrian   : " << P->info.nomorAntrian << endl;
            cout << "Prioritas       : " << P->info.prioritas << endl;
            cout << "===============================\n";
            ketemu = true;
            break;
        }
        P = P->nextC;
    }
    if (!ketemu){
        cout<<"Nama Pasien Tidak Ditemukan\n";
    }
}

void riwayatKunjungan(addressC firstChild, string namaPasien){
    addressC P = firstChild;
    bool ketemu = false;

    while (P != nullptr) {
        if (P->info.nama == namaPasien) {
            cout << "=== RIWAYAT KUNJUNGAN PASIEN ===\n";
            cout << "Nama             : " << P->info.nama << endl;
            cout << "Umur             : " << P->info.umur << endl;
            cout << "Penyakit         : " << P->info.penyakit << endl;
            cout << "ID               : " << P->info.ID << endl;
            cout << "Poli Tujuan      : " << P->info.poliTujuan << endl;
            cout << "Tanggal Kunjungan: " << P->info.tanggalKunjungan << endl;
            cout << "===============================\n";

            ketemu = true;
            break; // keluar karena data sudah ditemukan
        }
        P = P->nextC;
    }

    if (!ketemu) {
        cout << "Nama Pasien Tidak Ditemukan\n";
    }
}


void rataUmurPerPoli(addressC firstChild, string poliName){
    addressC P = firstChild;
    int totalUmur = 0;
    int jumlahPasien = 0;
    bool ketemu = false;
    float rataRata;

    while (P != nullptr) {
        if (P->info.poliTujuan == poliName) {
            totalUmur += P->info.umur;
            jumlahPasien++;
            ketemu = true;
        }
        P = P->nextC;
    }

    if (ketemu && jumlahPasien > 0) {
        rataRata = (float)((totalUmur) / jumlahPasien);
        cout << "Rata-rata umur pasien di poli " << poliName << " adalah: " << rataRata << " tahun.\n";
    } else {
        cout << "Tidak ada pasien di poli " << poliName << ".\n";
    }
}
