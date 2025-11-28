#ifndef POLI_H
#define POLI_H
#include "Pasien.h"
#include <iostream>
using namespace std;

struct Poli{
   string namaPoli;
   int IDPoli;
   string namaDokter;
   int kuotaPoli;
   int jumlahPasien;
};

typedef Poli infotypeP;
typedef struct elmenP *addressP;
struct elmenP{
    infotypeP infoP;
    addressP next;
    addressP prev;
    addressC firstChild;
};
struct ListParent{
    addressP first;
    addressP Last;
}

void createListParent(ListParent &L);
addressC createElementParent(Poli x);
void insertFirstParent(ListParent &L, addressP P);
void insertLastParent(ListParent &L, addressP P);
void insertAfterParent(ListParent &L, addressP P, addressP Prec);
addressC findParent(ListParent L, string nik);
void deleteFirstParent(ListParent &L, addressP &P);
void deleteLastParent(ListParent &L, addressP &P);
void deleteAfterParent(ListParent &L, addressP &P, addressP Prec);
void printInfoParent(ListParent L);  
bool isEmptyParent(ListParent L);
int hitungJumlahPasienPoli(ListParent L);
int hitungTotalKuota(ListParent L);







#endif