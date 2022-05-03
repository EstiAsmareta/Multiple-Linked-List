#include "list_parent.h"

void createList(List_parent &L) {
    //membuat list
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    //mengembalikan elemen list baru dengan info = x, next elemen = Null

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    //menambahkan data di awal list
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}


void printInfo(List_parent L) {
    // menampilkan info seluruh elemen list L
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            printInfo(child(P));
            P = next(P);
        } while((P)!=first(L));
    }
}

address_parent findElm(List_parent L, infotype_parent x) {
    //algoritma menmenukan data di dalam list
    address_parent P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}