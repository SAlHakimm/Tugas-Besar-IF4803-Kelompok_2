#include <iostream>
#include "../headers/Poli.h"
#include "../headers/Pasien.h" 
using namespace std;

void menuUser(ListParent &L, ListChild &P){
    int pilih;
    pilih = 0;
    while (pilih != 3) {
        cout << "============= Menu User ============\n";
        cout << "1. Studi Kasus 1 (Menghitung Jumlah Pasien di Poli)\n";
        cout << "2. Studi Kasus 2 ()\n";
        cout << "3. Back\n";
        cout << "=====================================\n";
        cout << "Choose option: ";
        cin >> pilih;

        if (pilih == 1){
            hitungJumlahPasienPoli(L);
        }else if(pilih == 2){
            hitungTotalKuota(L);
        }
    }
}
