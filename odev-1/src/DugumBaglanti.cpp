/**
* @file DugumBaglanti.cpp
* @description Bu dosya, DugumBaglanti sinifini ve fonksiyonlarını icerir.
* @course 1.Ogretim A Grubu
* @assignment 1.Odev
* @date 22 July 2023
* @author O.Emre Turhan (osman.turhan@ogr.sakarya.edu.tr), Mahmud Emre Baspehlivan
*/

#include "DugumBaglanti.hpp"
#include <iostream>

DugumBaglanti::DugumBaglanti() : onlarList(nullptr), birlerList(nullptr), next(nullptr) {}
DugumBaglanti::~DugumBaglanti() {
    Dugum* current;

    while(onlarList) {
        current = onlarList;
        onlarList = onlarList->next;
        delete current;
    }

    while(birlerList) {
        current = birlerList;
        birlerList = birlerList->next;
        delete current;
    }
}

void BagliListeyeEkle(Dugum*& head, int data) {
    Dugum* yeniDugum = new Dugum(data);
    if (!head) {
        head = yeniDugum;
    } else {
        Dugum* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = yeniDugum;
    }
}

void IndexIleBagliListeDegistir(DugumBaglanti* head, int onlarIndex, int birlerIndex) {
    DugumBaglanti* dugumBaglantiOnlar = IndexIleDugumBaglantiAl(head, onlarIndex);
    DugumBaglanti* dugumBaglantiBirler = IndexIleDugumBaglantiAl(head, birlerIndex);

    // Her iki DugumBaglanti da mevcut mu diye kontrol ediyoruz.
    if (dugumBaglantiOnlar && dugumBaglantiBirler) {
        Dugum* temp = dugumBaglantiOnlar->onlarList;
        dugumBaglantiOnlar->onlarList = dugumBaglantiBirler->birlerList;
        dugumBaglantiBirler->birlerList = temp;
    }
}

DugumBaglanti* IndexIleDugumBaglantiAl(DugumBaglanti* head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }
    return head;
}