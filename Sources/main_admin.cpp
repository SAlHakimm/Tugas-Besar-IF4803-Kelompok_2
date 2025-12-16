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
    int pilih = 0;
    dataPasien x;
    addressC P = nullptr, Prec = nullptr;
    addressP poli = nullptr;
    int idPoli, idPasien, idPrec;
    static int autoID = 1000;

    while (pilih != 9) {
        cout << "\n============= Menu Pasien ============\n";
        cout << "1. Insert First Pasien\n";
        cout << "2. Insert Last Pasien\n";
        cout << "3. Insert After Pasien\n";
        cout << "4. Delete First Pasien\n";
        cout << "5. Delete Last Pasien\n";
        cout << "6. Delete After Pasien\n";
        cout << "7. Cari Pasien\n";
        cout << "8. Tampilkan Semua Pasien\n";
        cout << "9. Back\n";
        cout << "Choose option: ";
        cin >> pilih;

        bool butuhPoli = (pilih >= 1 && pilih <= 6);

        if (butuhPoli) {
            cout << "Masukkan ID Poli: ";
            cin >> idPoli;
            poli = findParent(LC, idPoli);

            if (poli == nullptr) {
                cout << "Poli tidak ditemukan!\n";
            }
        }

        if (pilih == 1 && poli != nullptr) {
            cout << "Nama: "; cin >> x.nama;
            cout << "Umur: "; cin >> x.umur;
            cout << "Penyakit: "; cin >> x.penyakit;

            x.ID = autoID++;
            x.poliTujuan = poli->infoP.namaPoli;
            cout << "Tanggal: "; cin >> x.tanggalKunjungan;
            cout << "Antrian: "; cin >> x.nomorAntrian;
            cout << "Prioritas: "; cin >> x.prioritas;

            P = createElementChild(x);
            P->nextC = poli->firstChild;
            poli->firstChild = P;
            poli->infoP.jumlahPasien++;

            cout << "Pasien berhasil ditambahkan\n";

        }else if (pilih == 2 && poli != nullptr) {
            cout << "Nama: "; cin >> x.nama;
            cout << "Umur: "; cin >> x.umur;
            cout << "Penyakit: "; cin >> x.penyakit;

            x.ID = autoID++;
            x.poliTujuan = poli->infoP.namaPoli;
            cout << "Tanggal: "; cin >> x.tanggalKunjungan;
            cout << "Antrian: "; cin >> x.nomorAntrian;
            cout << "Prioritas: "; cin >> x.prioritas;

            P = createElementChild(x);

            if (poli->firstChild == nullptr)
                poli->firstChild = P;
            else {
                addressC Q = poli->firstChild;
                while (Q->nextC != nullptr)
                    Q = Q->nextC;
                Q->nextC = P;
            }

            poli->infoP.jumlahPasien++;
            cout << "Pasien berhasil ditambahkan\n";

        }else if (pilih == 3 && poli != nullptr) {
            cout << "Masukkan ID Pasien (Prec): ";
            cin >> idPrec;

            Prec = poli->firstChild;
            while (Prec != nullptr && Prec->info.ID != idPrec)
                Prec = Prec->nextC;

            if (Prec != nullptr) {
                cout << "Nama: "; cin >> x.nama;
                cout << "Umur: "; cin >> x.umur;
                cout << "Penyakit: "; cin >> x.penyakit;

                x.ID = autoID++;
                x.poliTujuan = poli->infoP.namaPoli;
                cout << "Tanggal: "; cin >> x.tanggalKunjungan;
                cout << "Antrian: "; cin >> x.nomorAntrian;
                cout << "Prioritas: "; cin >> x.prioritas;

                P = createElementChild(x);
                P->nextC = Prec->nextC;
                Prec->nextC = P;
                poli->infoP.jumlahPasien++;

                cout << "Insert After berhasil\n";
            } else {
                cout << "Pasien Prec tidak ditemukan\n";
            }

        }else if (pilih == 4 && poli != nullptr) {
            if (poli->firstChild != nullptr) {
                P = poli->firstChild;
                poli->firstChild = P->nextC;
                P->nextC = nullptr;
                poli->infoP.jumlahPasien--;

                cout << "Pasien dihapus\n";
            } else {
                cout << "Tidak ada pasien\n";
            }

        }else if (pilih == 5 && poli != nullptr) {
            if (poli->firstChild == nullptr)
                cout << "Tidak ada pasien\n";
            else if (poli->firstChild->nextC == nullptr) {
                P = poli->firstChild;
                poli->firstChild = nullptr;
                poli->infoP.jumlahPasien--;
                cout << "Pasien dihapus\n";
            } else {
                addressC Q = poli->firstChild;
                while (Q->nextC->nextC != nullptr)
                    Q = Q->nextC;
                P = Q->nextC;
                Q->nextC = nullptr;
                poli->infoP.jumlahPasien--;
                cout << "Pasien dihapus\n";
            }

        }else if (pilih == 6 && poli != nullptr) {
            cout << "Masukkan ID Pasien (Prec): ";
            cin >> idPrec;

            Prec = poli->firstChild;
            while (Prec != nullptr && Prec->info.ID != idPrec)
                Prec = Prec->nextC;

            if (Prec != nullptr && Prec->nextC != nullptr) {
                P = Prec->nextC;
                Prec->nextC = P->nextC;
                P->nextC = nullptr;
                poli->infoP.jumlahPasien--;
                cout << "Pasien dihapus\n";
            } else {
                cout << "Delete After gagal\n";
            }

        }else if (pilih == 7) {
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;

            bool ketemu = false;
            addressP par = LC.first;

            while (par != nullptr && !ketemu) {
                addressC c = par->firstChild;
                while (c != nullptr) {
                    if (c->info.ID == idPasien) {
                        cout << "Nama: " << c->info.nama << endl;
                        cout << "Poli: " << par->infoP.namaPoli << endl;
                        ketemu = true;
                        break;
                    }
                    c = c->nextC;
                }
                par = par->next;
            }

            if (!ketemu){
                cout << "Pasien tidak ditemukan\n";
            }

        } else if (pilih == 8) {
            addressP q = LC.first;
            while (q != nullptr) {
                cout << "\n=== POLI " << q->infoP.namaPoli << " ===\n";
                printInfoChild(q->firstChild);
                q = q->next;
            }
        }
    }
}
