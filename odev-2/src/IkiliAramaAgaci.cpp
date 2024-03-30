/** 
* @file IkiliAramaAgaci.cpp
* @description Bu dosya programin IkiliAramaAgaci sinifini ve metodlarini icerir. Ayni zamanda ekrana 
    yazdirma islemini saglayan metod olan postOrderYazdir() metodunu da buradadir.
* @course 1.Ogretim B Grubu
* @assignment 2.Odev
* @date 05 Aug 2023
* @author O.Emre Turhan (osman.turhan@ogr.sakarya.edu.tr), Mahmud Emre Baspehlivan (emre.baspehlivan@ogr.sakarya.edu.tr)
*/

#include "IkiliAramaAgaci.hpp"

void IkiliAramaAgaci::insert(IkiliAramaAgaciDugum*& simdiki, int deger) {
    if (!simdiki) {
        simdiki = new IkiliAramaAgaciDugum(deger);
    } else if (deger < simdiki->veri) {
        insert(simdiki->sol, deger);
    } else if (deger > simdiki->veri) {
        insert(simdiki->sag, deger);
    }
}

int IkiliAramaAgaci::uzunlukGetir(IkiliAramaAgaciDugum* dugum) const {
    if (!dugum) {
        return 0;
    }
    int solUzunluk = uzunlukGetir(dugum->sol);
    int sagUzunluk = uzunlukGetir(dugum->sag);
    return std::max(solUzunluk, sagUzunluk) + 1;
}

int IkiliAramaAgaci::toplamDegerGetir(IkiliAramaAgaciDugum* dugum) const {
    if (!dugum) {
        return 0;
    }
    return dugum->veri + toplamDegerGetir(dugum->sol) + toplamDegerGetir(dugum->sag);
}

void IkiliAramaAgaci::postOrderYazdir(IkiliAramaAgaciDugum* dugum) const {
    if (dugum) {
        postOrderYazdir(dugum->sol);
        postOrderYazdir(dugum->sag);
        char ch = static_cast<char>(dugum->veri);
        std::cout << ch << " ";
    }
}

void IkiliAramaAgaci::agacSil(IkiliAramaAgaciDugum* dugum) {
    if (dugum) {
        agacSil(dugum->sol);
        agacSil(dugum->sag);
        delete dugum;
    }
}

IkiliAramaAgaci::IkiliAramaAgaci() : kok(nullptr), nextIkiliAramaAgaci(nullptr) {}

void IkiliAramaAgaci::insert(int deger) {
    insert(kok, deger);
}

int IkiliAramaAgaci::uzunlukGetir() const {
    return uzunlukGetir(kok);
}

int IkiliAramaAgaci::toplamDegerGetir() const {
    return toplamDegerGetir(kok);
}

void IkiliAramaAgaci::postOrderYazdir() const {
    postOrderYazdir(kok);
}

void IkiliAramaAgaci::setNext(IkiliAramaAgaci* nextAgac) {
    nextIkiliAramaAgaci = nextAgac;
}

IkiliAramaAgaci* IkiliAramaAgaci::getNext() const {
    return nextIkiliAramaAgaci;
}

IkiliAramaAgaci::~IkiliAramaAgaci() {
    agacSil(kok);
}
