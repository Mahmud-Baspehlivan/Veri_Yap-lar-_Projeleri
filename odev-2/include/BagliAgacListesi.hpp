#ifndef BAGLIAGACLISTESI_HPP
#define BAGLIAGACLISTESI_HPP

#include "IkiliAramaAgaci.hpp"

class BagliAgacListesi {
private:
    IkiliAramaAgaci* head;
    IkiliAramaAgaci* tail;

public:
    BagliAgacListesi();
    ~BagliAgacListesi();

    void agacEkle(IkiliAramaAgaci* agac);
    IkiliAramaAgaci* enYuksekAgacGetir();
};

#endif // BAGLIAGACLISTESI_HPP
