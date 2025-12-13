#include <iostream>
#include "Poli.h"
#include "Pasien.h"
using namespace std;

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

            if (!ketemu)
                cout << "Pasien tidak ditemukan\n";
        }

        else if (pilih == 2) {
            printInfoParent(L);
        } else if (pilih == 3) {
            cout << "Masukkan Nama Pasien: ";
            cin >> nama;

            addressP P = L.first;
            while (P != nullptr) {
                riwayatPenyakit(P->firstChild, nama);
                P = P->next;
            }
        } else if (pilih == 4) {
            cout << "Masukkan Nama Pasien: ";
            cin >> nama;

            addressP P = L.first;
            while (P != nullptr) {
                riwayatKunjungan(P->firstChild, nama);
                P = P->next;
            }
        }

         else if (pilih == 5) {
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
