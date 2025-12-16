#include <iostream>
#include "Poli.h"
#include "Pasien.h"
using namespace std;
void initDummyData(ListParent &L);

void menuUser(ListParent &L){
    int pilih = 0;
    int id;
    string nama, poli;

    while (pilih != 6) {
        cout << "\n====== MENU USER ======\n";
        cout << "1. Cari Pasien berdasarkan ID\n";
        cout << "2. Tampilkan Semua Pasien\n";
        cout << "3. Riwayat Penyakit Pasien\n";
        cout << "4. Riwayat Kunjungan Pasien\n";
        cout << "5. Rata-rata Umur per Poli\n";
        cout << "6. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan ID Pasien: ";
            cin >> id;

            addressP P = L.first;
            bool ketemu = false;

            while (P != nullptr) {
                addressC C = P->firstChild;
                while (C != nullptr) {
                    if (C->info.ID == id) {
                        cout << "Nama: " << C->info.nama << endl;
                        cout << "Poli: " << P->infoP.namaPoli << endl;
                        ketemu = true;
                        break;
                    }
                    C = C->nextC;
                }
                if (ketemu) break;
                P = P->next;
            }

            if (!ketemu){
                cout << "Pasien tidak ditemukan\n";
            }

        }else if (pilih == 2) {
            printInfoParent(L);

        }else if (pilih == 3) {
            cout << "Masukkan Nama Pasien: ";
            cin >> nama;

            addressP P = L.first;
            bool ketemu = false;

            while (P != nullptr) {
                addressC C = P->firstChild;
                while (C != nullptr) {
                    if (C->info.nama == nama) {
                        ketemu = true;
                        break;
                    }
                    C = C->nextC;
                }
                riwayatPenyakit(P->firstChild, nama);
                P = P->next;
            }

            if (!ketemu) {
                cout << "Nama Pasien Tidak Ditemukan\n";
            }

        }else if (pilih == 4) {
            cout << "Masukkan Nama Pasien: ";
            cin >> nama;

            addressP P = L.first;
            bool ketemu = false;

            while (P != nullptr) {
                addressC C = P->firstChild;
                while (C != nullptr) {
                    if (C->info.nama == nama) {
                        ketemu = true;
                        break;
                    }
                    C = C->nextC;
                }

                riwayatKunjungan(P->firstChild, nama);
                P = P->next;
            }

            if (!ketemu) {
                cout << "Nama Pasien Tidak Ditemukan\n";
            }

        }else if (pilih == 5) {
            cout << "Masukkan Nama Poli: ";
            cin >> poli;

            addressP P = L.first;
            bool ketemu = false;

            while (P != nullptr) {
                if (P->infoP.namaPoli == poli) {
                    rataUmurPerPoli(P->firstChild, poli);
                    ketemu = true;
                    break;
                }
                P = P->next;
            }

            if (!ketemu) {
                cout << "Poli tidak ditemukan\n";
            }
        }
    }
}

void initDummyData(ListParent &L) {
    Poli p;
    dataPasien x;

    int idPoli = 1;
    int idPasien = 100;

    // ===== POLI UMUM =====
    p.IDPoli = idPoli++;
    p.namaPoli = "Umum";
    p.namaDokter = "DrAndi";
    p.kuotaPoli = 20;
    p.jumlahPasien = 0;
    addressP poli1 = createElementParent(p);
    insertLastParent(L, poli1);

    // ===== POLI GIGI =====
    p.IDPoli = idPoli++;
    p.namaPoli = "Gigi";
    p.namaDokter = "DrBudi";
    p.kuotaPoli = 15;
    p.jumlahPasien = 0;
    addressP poli2 = createElementParent(p);
    insertLastParent(L, poli2);

    // ===== POLI ANAK =====
    p.IDPoli = idPoli++;
    p.namaPoli = "Anak";
    p.namaDokter = "DrCitra";
    p.kuotaPoli = 10;
    p.jumlahPasien = 0;
    addressP poli3 = createElementParent(p);
    insertLastParent(L, poli3);

    // ===== PASIEN POLI UMUM =====
    poli1->firstChild = createElementChild(
        {"Ayu", 20, "Flu", idPasien++, "Umum", "2024-01-01", 1, "Normal"}
    );
    poli1->firstChild->nextC = createElementChild(
        {"Bima", 30, "Demam", idPasien++, "Umum", "2024-01-01", 2, "Normal"}
    );
    poli1->infoP.jumlahPasien = 2;

    // ===== PASIEN POLI GIGI =====
    poli2->firstChild = createElementChild(
        {"Caca", 25, "Gigi", idPasien++, "Gigi", "2024-01-02", 1, "Normal"}
    );
    poli2->firstChild->nextC = createElementChild(
        {"Dimas", 28, "SakitGigi", idPasien++, "Gigi", "2024-01-02", 2, "Normal"}
    );
    poli2->infoP.jumlahPasien = 2;

    // ===== PASIEN POLI ANAK =====
    poli3->firstChild = createElementChild(
        {"Evan", 5, "Batuk", idPasien++, "Anak", "2024-01-03", 1, "Prioritas"}
    );
    poli3->firstChild->nextC = createElementChild(
        {"Fina", 6, "Demam", idPasien++, "Anak", "2024-01-03", 2, "Normal"}
    );
    poli3->infoP.jumlahPasien = 2;
}
