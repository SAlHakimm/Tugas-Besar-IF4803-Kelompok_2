#include <iostream>
#include "Poli.h"
using namespace std;

void createListParent(ListParent &L){
    L.first = nullptr;
    L.Last = nullptr;
}

void insertFirstParent(ListParent &L, addressP P){
    if (L.first == nullptr && L.Last == nullptr){
        L.first = P;
        L.Last == P;
    }else{
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfterParent(ListParent &L, addressP P, addressP Prec){
    //I.S: List terdefinisi dan tidak pada First atau Last
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;       
    Prec->next = P;
}

void deleteFirstParent(ListParent &L, addressP &P){
     if (L.first == nullptr && L.Last == nullptr){
        P = nullptr;
    }else if (L.first == L.Last){
        P = L.first;
        L.first = nullptr;
        L.Last = nullptr;
    }else{
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
        L.first->prev = nullptr;
    }
}

void deleteAfterParent(ListParent &L, addressP &P, addressP Prec){
    //I.S: List terdefinisi dan tidak pada First atau Last
    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = NULL;
    P->prev = NULL;
}

bool isEmptyParent(ListParent L){
    return L.first == nullptr && L.Last == nullptr;
}

int hitungTotalKuota(ListParent L){
    int total = 0;
    addressP P = L.first;

    while (P != nullptr) {
        total += P->infoP.kuotaPoli;
        P = P->next;
    }

    return total;
}


