#include "list_child.h"

void createList(List_child &L) {
  //membuat list
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
  //mengembalikan elemen list baru dengan info = x, next elemen = Null
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
  //menambahkan data di awal pada list list
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_child L) {
  //menampilkan rujukan list parent setelah di isi child
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P)<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child Prec, address_child P) {
  //menambahkan data di akhir pada list
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}