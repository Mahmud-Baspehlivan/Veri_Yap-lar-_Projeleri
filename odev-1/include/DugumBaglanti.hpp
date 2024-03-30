#ifndef DUGUMBAGLANTI_HPP
#define DUGUMBAGLANTI_HPP

#include "Dugum.hpp"
#include <iostream>

class DugumBaglanti {
public:
    Dugum* onlarList;
    Dugum* birlerList;
    DugumBaglanti* next;

    DugumBaglanti();
    ~DugumBaglanti();
};

void BagliListeyeEkle(Dugum*& head, int data);
void IndexIleBagliListeDegistir(DugumBaglanti* head, int onlarIndex, int birlerIndex);
DugumBaglanti* IndexIleDugumBaglantiAl(DugumBaglanti* head, int index);

#endif // DUGUMBAGLANTI_HPP
