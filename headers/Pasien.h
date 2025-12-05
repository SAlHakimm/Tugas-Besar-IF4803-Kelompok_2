#ifndef PASIEN_H
#define PASIEN_H
#include "Poli.h"
#include <iostream>
using namespace std;

struct dataPasien {
    string nama;
    int umur;
    string penyakit;
    int ID;
    string poliTujuan;
    string tanggalKunjungan;
    int nomorAntrian;
    string prioritas;
};

typedef struct elmPasien *addressC;
typedef struct elmPasien {
    dataPasien info;
    addressC nextC;
};

typedef struct ListChild{
    addressC firstC;
};

void createListChild(ListChild &L);
addressC createElementChild(dataPasien x);
void insertFirstChild(ListChild &L, addressC P);
void insertLastChild(ListChild &L, addressC P);
void insertAfterChild(ListChild &L, addressC P, addressC Prec);
addressC findChild(ListChild L, int ID);
void deleteFirstChild(ListChild &L, addressC &P);
void deleteLastChild(ListChild &L, addressC &P);
void deleteAfterChild(ListChild &L, addressC &P, addressC Prec);
void printInfoChild(ListChild L);  
bool isEmptyChild(ListChild L);
void searchByID(ListChild L, int ID);
void sortByUmur(ListChild &L);
void countPasienPerPoli(ListChild L, string poliName);

#endif