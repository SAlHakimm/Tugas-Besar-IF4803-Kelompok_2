#include <iostream>
#include "../headers/Poli.h"
#include "../headers/Pasien.h" 
using namespace std;

void menuUser(ListParent &L, ListChild &P){
    addressC Pasien;
    dataPasien x;
    int pilih;
    string nama;
    pilih = 0;
    while (pilih != 12) {
        cout << "============= Menu User ============\n";
        cout << "1. Insert First Pasien\n";
        cout << "2. Insert Last Pasien\n";
        cout << "3. Insert After Pasien (Pasien Harus Sudah Diisi Sebelumnya)\n";
        cout << "4. Delete First Pasien\n";
        cout << "5. Delete Last Pasien\n";
        cout << "6. Delete After Pasien (Pasien Harus Sudah Diisi Sebelumnya)\n";
        cout << "7. Cari Pasien Berdasarkan ID\n";
        cout << "8. Tampilkan Seluruh Pasien\n";
        cout << "9. Studi Kasus 1 (Riwayat Penyakit)\n";
        cout << "10. Studi Kasus 2 (Riwayat Kunjungan)\n";
        cout << "11. Studi Kasus 3 (Rata Rata Umur Perpoli)\n";
        cout << "12. Back\n";
        cout << "=====================================\n";
        cout << "Choose option: ";
        cin >> pilih;

        
        if (pilih == 1 || pilih == 2|| pilih == 3){
            cout << "Masukkan Nama Pasien: ";
            cin >> x.nama;
            cout << "Masukkan Umur Pasien: ";
            cin >> x.umur;
            cout << "Masukkan Penyakit Pasien: ";
            cin >> x.penyakit;
            cout << "Masukkan ID Pasien: ";
            cin >> x.ID;
            cout << "Masukkan Poli Tujuan Pasien: ";
            cin >> x.poliTujuan;
            cout << "Masukkan Tanggal Kunjungan Pasien: ";
            cin >> x.tanggalKunjungan;
            cout << "Masukkan Nomor Antrian Pasien: ";
            cin >> x.nomorAntrian;
            cout << "Masukkan Prioritas Pasien: ";
            cin >> x.prioritas;
            Pasien = createElementChild(x);
            if (pilih == 1){
                insertFirstChild(P, Pasien);
            }else if (pilih == 2){
                insertLastChild(P, Pasien);
            }else if (pilih == 3){
                addressC Prec;
                cout << "Masukkan NIK Pasien: ";
                string nik;
                cin >> nik;
                Prec = findChild(P, nik);
                if (Prec != nullptr){
                    insertAfterChild(P, Pasien, Prec);
                }else{
                    cout<<"ID Pasien Prec Tidak Ditemukan\n";
                }
            }
        }else if (pilih == 4){
            deleteFirstChild(P, Pasien);
            cout << "Data Berhasil Dihapus! \n";
        }else if (pilih == 5){
            deleteLastChild(P, Pasien); 
            cout << "Data Berhasil Dihapus! \n";
        }else if (pilih == 6){
            addressC Prec;
            cout << "Masukkan NIK Pasien Prec: ";
            string nik;
            cin >> nik;
            Prec = findChild(P, nik);
            if (Prec != nullptr){
                deleteAfterChild(P,  Pasien, Prec);
                cout << "Data Berhasil Dihapus! \n";
            }else{
                cout<<"ID Pasien Prec Tidak Ditemukan\n";
            }
        }else if (pilih == 7){
            string nik;
            cout << "Masukkan NIK Pasien: ";
            cin >> nik;
            findChild(P, nik);
        }else if (pilih == 8){
            printInfoChild(P);
        }else if (pilih == 9){
            cout << "Masukkan Nama Pasien: ";
            cin >> nama;
            riwayatPenyakit(P, nama);
        }else if(pilih == 10){
            cout << "Masukkan Nama Pasien: ";
            cin >> nama;
            riwayatKunjungan(P, nama);
        }else if(pilih == 11){
            cout << "Masukkan Nama Poli: ";
            cin >> nama;
            rataUmurPerPoli(P, nama);
        }
    }
}

