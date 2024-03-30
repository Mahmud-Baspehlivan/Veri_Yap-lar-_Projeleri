/** 
* @file BagliAgacListesi.cpp
* @description Bu dosya programin BagliAgacListesi sinifini ve metodlarini icerir. IkiliAramaAgaclarini tutan yapidir.
* @course 1.Ogretim B Grubu
* @assignment 2.Odev
* @date 05 Aug 2023
* @author O.Emre Turhan (osman.turhan@ogr.sakarya.edu.tr), Mahmud Emre Baspehlivan (emre.baspehlivan@ogr.sakarya.edu.tr)
*/

#include "BagliAgacListesi.hpp"

BagliAgacListesi::BagliAgacListesi() : head(nullptr), tail(nullptr) {}

BagliAgacListesi::~BagliAgacListesi() {
    IkiliAramaAgaci* simdiki = head;
    while (simdiki) {
        IkiliAramaAgaci* nextAgac = simdiki->getNext();
        delete simdiki;
        simdiki = nextAgac;
    }
}

void BagliAgacListesi::agacEkle(IkiliAramaAgaci* agac) {
    if (!head) {
        head = tail = agac;
    } else {
        tail->setNext(agac);
        tail = agac;
    }
}

IkiliAramaAgaci* BagliAgacListesi::enYuksekAgacGetir() {
    IkiliAramaAgaci* enYuksekAgac = head;
    int enYuksekUzunluk = -1;
    int enYuksekDeger = -1;

    IkiliAramaAgaci* simdiki = head;
    while (simdiki) {
        int simdikiUzunluk = simdiki->uzunlukGetir();
        int simdikiDeger = simdiki->toplamDegerGetir();

        if (simdikiUzunluk > enYuksekUzunluk || (simdikiUzunluk == enYuksekUzunluk && simdikiDeger > enYuksekDeger)) {
            enYuksekUzunluk = simdikiUzunluk;
            enYuksekDeger = simdikiDeger;
            enYuksekAgac = simdiki;
        }

        simdiki = simdiki->getNext();
    }

    return enYuksekAgac;
}
