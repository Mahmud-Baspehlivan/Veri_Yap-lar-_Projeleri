#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP

#include "IkiliAramaAgaciDugum.hpp"
#include <iostream>

class IkiliAramaAgaci {
private:
    IkiliAramaAgaciDugum* kok;
    IkiliAramaAgaci* nextIkiliAramaAgaci;

    void insert(IkiliAramaAgaciDugum*& simdiki, int deger);
    int uzunlukGetir(IkiliAramaAgaciDugum* dugum) const;
    int toplamDegerGetir(IkiliAramaAgaciDugum* dugum) const;
    void postOrderYazdir(IkiliAramaAgaciDugum* dugum) const;
    void agacSil(IkiliAramaAgaciDugum* dugum);

public:
    IkiliAramaAgaci();

    void insert(int deger);
    int uzunlukGetir() const;
    int toplamDegerGetir() const;
    void postOrderYazdir() const;
    void setNext(IkiliAramaAgaci* nextAgac);
    IkiliAramaAgaci* getNext() const;

    ~IkiliAramaAgaci();
};

#endif // IKILIARAMAAGACI_HPP
