#include <iostream>
#include "Poli.h"
#include "Pasien.h"
using namespace std;

void menuPoli(ListParent &LP);
void menuPasien(ListParent &LP);

void menuAdmin(ListParent &L){
    int pilih;
    pilih = 0;
    while (pilih != 3) {
        cout << endl;
        cout << "============= Menu Admin ============\n";
        cout << "1. Poli\n";
        cout << "2. Pasien\n";
        cout << "3. Back\n";
        cout << "=====================================\n";
        cout << "Choose option: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1){
            menuPoli(L);
        }else if(pilih == 2){
            menuPasien(L);
        }
    }
}

void menuPoli(ListParent &LP){
    int pilih = 0;
    Poli x;
    addressP P = nullptr;
    addressP Prec = nullptr;
    static int i = 1000;
    while (pilih != 9) {
        cout << endl;
        cout << "============= Menu Poli ============\n";
        cout << "1. Insert First Poli\n";
        cout << "2. Insert Last Poli\n";
        cout << "3. Insert After Poli (Poli Harus Sudah Diisi Sebelumnya)\n";
        cout << "4. Delete First Poli\n";
        cout << "5. Delete Last Poli\n";
        cout << "6. Delete After Poli (Poli Harus Sudah Diisi Sebelumnya)\n";
        cout << "7. Cari Poli Berdasarkan ID\n";
        cout << "8. Tampilkan Seluruh Poli\n";
        cout << "9. Back\n";
        cout << "=====================================\n";
        cout << "Choose option: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1){
            cout << "Masukan Nama Poli: ";
            cin >> x.namaPoli;
            cout << "ID Poli: ";
            x.IDPoli = i++;
            cout << x.IDPoli;
            cout << "\n";
            cout << "Masukan Nama Dokter: ";
            cin >> x.namaDokter;
            cout << "Masukan Kuota Poli: ";
            cin >> x.kuotaPoli;
            cout << "Jumlah Pasien: ";
            x.jumlahPasien = 0;
            cout << x.jumlahPasien;
            cout << endl;
            P = createElementParent(x);
            insertFirstParent(LP, P);
        }else if(pilih == 2){
            cout << "Masukan Nama Poli: ";
            cin >> x.namaPoli;
            cout << "ID Poli: ";
            x.IDPoli = i++;
            cout << x.IDPoli;
            cout << "\n";
            cout << "Masukan Nama Dokter: ";
            cin >> x.namaDokter;
            cout << "Masukan Kuota Poli: ";
            cin >> x.kuotaPoli;
            cout << "Jumlah Pasien: ";
            x.jumlahPasien = 0;
            cout << x.jumlahPasien;
            P = createElementParent(x);
            insertLastParent(LP, P);
            cout << endl;
        }else if(pilih == 3){
            int idPrec;
            cout << "--- Insert After Poli ---\n";
            cout << "Masukkan ID Poli Prec (Elemen Sebelum): ";
            cin >> idPrec;
            Prec = findParent(LP, idPrec);
            if (Prec != NULL) {
                cout << "Masukan Nama Poli Baru: ";
                cin >> x.namaPoli;
                cout << "ID Poli Baru: ";
                x.IDPoli = i++;
                cout << x.IDPoli;
                cout << "\n";
                cout << "Masukan Nama Dokter Baru: ";
                cin >> x.namaDokter;
                cout << "Masukan Kuota Poli Baru: ";
                cin >> x.kuotaPoli;
                cout << "Jumlah Pasien: ";
                x.jumlahPasien = 0;
                cout << x.jumlahPasien;
                cout << endl;
                P = createElementParent(x);
                insertAfterParent(LP, P, Prec);
                cout << "Poli berhasil disisipkan setelah ID " << idPrec << "\n";
                } else {
                    cout << "Poli dengan ID Prec " << idPrec << " tidak ditemukan!\n";
                }
        }else if (pilih == 4){
            deleteFirstParent(LP, P);
            cout << "Data Berhasil Dihapus! \n";
        }else if (pilih == 5){
            deleteLastParent(LP, P);
            cout << "Data Berhasil Dihapus! \n";
        }else if (pilih == 6){
            int idPrec;
            cout << "\n--- Delete After Poli ---\n";
            cout << "Masukkan ID Poli Prec (elemen sebelum yang akan dihapus): ";
            cin >> idPrec;
            Prec = findParent(LP, idPrec);

            if (Prec == NULL) {
                cout << ">> Poli dengan ID " << idPrec << " tidak ditemukan!\n";
            }
            else if (Prec->next == NULL) {
                cout << ">> Tidak ada elemen setelah ID " << idPrec << " (Prec adalah elemen terakhir).\n";
            }
            else {
                deleteAfterParent(LP, P, Prec);
                if (P != NULL) {
                    cout << ">> Poli dengan ID " << P->infoP.IDPoli
                    << " berhasil dihapus (setelah ID " << idPrec << ").\n";
                } else {
                    cout << ">> Tidak ada elemen yang dapat dihapus setelah ID tersebut.\n";
                }
            }
        }else if (pilih == 7){
            int id;
            cout << "Masukan ID Poli Yang Akan dicari: ";
            cin >> id;

            addressP P = findParent(LP, id);
            if (P != nullptr) {
                cout << "Poli ditemukan!\n";
                cout << "Nama Poli: " << P->infoP.namaPoli << endl;
                cout << "Dokter: " << P->infoP.namaDokter << endl;
                cout << "Kuota: " << P->infoP.kuotaPoli << endl;
            } else {
                cout << "Poli tidak ditemukan!\n";
            }

        }else if (pilih == 8){
            cout << endl;
            cout << "===============Poli===============\n";
            printInfoParent(LP);
        }else if (pilih == 9){
            cout << "Kembali Ke Menu Admin";
            cout << "\n";
        }else{
            cout << "Pilihan Tidak Valid";
            cout << "\n";
        }
    }
}

void menuPasien(ListParent &LC){
    int pilih;
    dataPasien x;
    addressC P, Prec;
    addressP poli;
    int idPoli, idPasien, idPrec;
    static int autoID = 100;
    pilih = 0;
    while (pilih != 9) {
        cout << endl;
        cout << "============= Menu Pasien ============\n";
        cout << "1. Insert First Pasien ke Poli\n";
        cout << "2. Insert Last Pasien ke Poli\n";
        cout << "3. Insert After Pasien (berdasarkan ID Pasien pada Poli)\n";
        cout << "4. Delete First Pasien dari Poli\n";
        cout << "5. Delete Last Pasien dari Poli\n";
        cout << "6. Delete After Pasien dari Poli\n";
        cout << "7. Cari Pasien Berdasarkan ID (semua poli)\n";
        cout << "8. Tampilkan Seluruh Pasien (semua poli)\n";
        cout << "9. Back\n";
        cout << "=====================================\n";
        cout << "Choose option: ";
        cin >> pilih;
        cout << endl;

        // Untuk pilihan yang memerlukan poli, minta ID poli dan cari parent
        if (pilih >= 1 && pilih <= 6) {
            cout << "Masukkan ID Poli Yang Pasien Akan Kunjungi: ";
            cin >> idPoli;

            poli = findParent(LC, idPoli);

            if (poli == nullptr) {
                cout << "Poli tidak ditemukan!\n";
                continue;
            }
        }

        if (pilih == 1) {
            cout << "Nama: ";
            cin >> x.nama;
            cout << "Umur: ";
            cin >> x.umur;
            cout << "Penyakit: ";
            cin >> x.penyakit;

            x.ID = autoID++;
            cout << "ID Pasien = " << x.ID << endl;

            x.poliTujuan = poli->infoP.namaPoli;
            cout << "Tanggal Kunjungan: ";
            cin >> x.tanggalKunjungan;
            cout << "Nomor Antrian: ";
            cin >> x.nomorAntrian;
            cout << "Prioritas: ";
            cin >> x.prioritas;

            P = createElementChild(x);

            // bungkus poli->firstChild ke ListChild sementara
            ListChild tempChild;
            tempChild.firstC = poli->firstChild;

            insertFirstChild(tempChild, P);

            // simpan kembali ke node parent
            poli->firstChild = tempChild.firstC;
            poli->infoP.jumlahPasien++;

            cout << "Pasien berhasil ditambahkan!\n";
        } else if (pilih == 2) {
            cout << "Nama: ";
            cin >> x.nama;
            cout << "Umur: ";
            cin >> x.umur;
            cout << "Penyakit: ";
            cin >> x.penyakit;

            x.ID = autoID++;
            cout << "ID Pasien = " << x.ID << endl;

            x.poliTujuan = poli->infoP.namaPoli;
            cout << "Tanggal Kunjungan: ";
            cin >> x.tanggalKunjungan;
            cout << "Nomor Antrian: ";
            cin >> x.nomorAntrian;
            cout << "Prioritas: ";
            cin >> x.prioritas;

            P = createElementChild(x);

            ListChild tempChild;
            tempChild.firstC = poli->firstChild;

            insertLastChild(tempChild, P);

            poli->firstChild = tempChild.firstC;
            poli->infoP.jumlahPasien++;

            cout << "Pasien berhasil ditambahkan!\n";
        } else if (pilih == 3) {
            cout << "Masukkan ID Pasien (Prec): ";
            cin >> idPrec;

            // Cari Prec pada daftar pasien poli tersebut
            Prec = poli->firstChild;
            while (Prec != nullptr && Prec->info.ID != idPrec)
                Prec = Prec->nextC;

            if (Prec == nullptr) {
                cout << "Pasien Prec tidak ditemukan!\n";
                continue;
            }

            cout << "Nama: ";
            cin >> x.nama;
            cout << "Umur: ";
            cin >> x.umur;
            cout << "Penyakit: ";
            cin >> x.penyakit;

            x.ID = autoID++;
            cout << "ID Pasien Baru = " << x.ID << endl;

            x.poliTujuan = poli->infoP.namaPoli;
            cout << "Tanggal Kunjungan: ";
            cin >> x.tanggalKunjungan;
            cout << "Nomor Antrian: ";
            cin >> x.nomorAntrian;
            cout << "Prioritas: ";
            cin >> x.prioritas;

            P = createElementChild(x);

            ListChild tempChild;
            tempChild.firstC = poli->firstChild;

            insertAfterChild(tempChild, P, Prec);

            poli->firstChild = tempChild.firstC;
            poli->infoP.jumlahPasien++;

            cout << "Insert After berhasil!\n";
        } else if (pilih == 4) {
            ListChild tempChild;
            tempChild.firstC = poli->firstChild;

            deleteFirstChild(tempChild, P);
            poli->firstChild = tempChild.firstC;

            if (P != nullptr) {
                cout << "Pasien \"" << P->info.nama << "\" berhasil dihapus!\n";
                poli->infoP.jumlahPasien--;
            } else {
                cout << "Tidak ada pasien di poli ini.\n";
            }
        } else if (pilih == 5) {
            ListChild tempChild;
            tempChild.firstC = poli->firstChild;

            deleteLastChild(tempChild, P);
            poli->firstChild = tempChild.firstC;

            if (P != nullptr) {
                cout << "Pasien \"" << P->info.nama << "\" berhasil dihapus!\n";
                poli->infoP.jumlahPasien--;
            } else {
                cout << "Tidak ada pasien di poli ini.\n";
            }
        } else if (pilih == 6) {
            cout << "Masukkan ID Pasien (Prec): ";
            cin >> idPrec;

            Prec = poli->firstChild;
            while (Prec != nullptr && Prec->info.ID != idPrec)
                Prec = Prec->nextC;

            if (Prec == nullptr || Prec->nextC == nullptr) {
                cout << "Delete After gagal (Prec tidak valid)\n";
            } else {
                ListChild tempChild;
                tempChild.firstC = poli->firstChild;

                deleteAfterChild(tempChild, P, Prec);
                poli->firstChild = tempChild.firstC;

                if (P != nullptr) {
                    cout << "Pasien \"" << P->info.nama << "\" berhasil dihapus!\n";
                    poli->infoP.jumlahPasien--;
                } else {
                    cout << "Delete After gagal (tidak ada node di posisi tersebut)\n";
                }
            }
        } else if (pilih == 7) {
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;

            addressP temp = LC.first;
            bool found = false;

            while (temp != nullptr) {
                P = temp->firstChild;
                while (P != nullptr) {
                    if (P->info.ID == idPasien) {
                        cout << "\n=== PASIEN DITEMUKAN ===\n";
                        cout << "Nama: " << P->info.nama << endl;
                        cout << "Poli: " << temp->infoP.namaPoli << endl;
                        found = true;
                        break;
                    }
                    P = P->nextC;
                }
                if (found) break;
                temp = temp->next;
            }

            if (!found)
                cout << "Pasien tidak ditemukan!\n";
        } else if (pilih == 8) {
            addressP q = LC.first;

            while (q != nullptr) {
                cout << "\n=== POLI: " << q->infoP.namaPoli << " ===\n";
                // bungkus q->firstChild ke ListChild supaya printInfoChild kompatibel
                ListChild tempChild;
                tempChild.firstC = q->firstChild;
                printInfoChild(tempChild);
                q = q->next;
            }
        } else if (pilih == 9) {
            cout << "Kembali ke menu Admin...\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}
