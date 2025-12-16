#include <iostream>
#include "../headers/Poli.h"
#include "../headers/Pasien.h"

using namespace std;

ListParent ListPoli;

void menuAdmin(ListParent &L);
void menuUser(ListParent &L);
void initDummyData(ListParent &L);

int main(){
    createListParent(ListPoli);
    initDummyData(ListPoli);

    int pilihan = 0;
    while (pilihan != 3) {
        cout << endl;
        cout << "============= Selamat Datang di Aplikasi ============\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "======================================================\n";
        cout << "Choose option: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1){
            menuAdmin(ListPoli);
        }else if(pilihan == 2){
            menuUser(ListPoli);
        }else if(pilihan == 3){
            cout << "Terimakasih Telah Menggunakan Aplikasi\n";
        }else{
            cout << "Pilihan Invalid\n";
        }
    }
    return 0;
}
