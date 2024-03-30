/** 
* @file main.cpp
* @description Bu dosya programin main fonksiyonunu icerir.
* @course 1.Ogretim B Grubu
* @assignment 2.Odev
* @date 06 Aug 2023
* @author O.Emre Turhan (osman.turhan@ogr.sakarya.edu.tr), Mahmud Emre Baspehlivan (emre.baspehlivan@ogr.sakarya.edu.tr)
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "Yigit.hpp"
#include "IkiliAramaAgaciDugum.hpp"
#include "IkiliAramaAgaci.hpp"
#include "BagliAgacListesi.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Lutfen bir dosya adi girin." << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Dosya acilamadi." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int sayi;
        Yigit yigit;
        BagliAgacListesi agaclarListesi;

        IkiliAramaAgaci* simdikiAgac = new IkiliAramaAgaci();

        while (iss >> sayi) {
            if (yigit.isEmpty() || (sayi % 2 == 0 && sayi > yigit.topDeger())) {
                while (!yigit.isEmpty()) {
                    simdikiAgac->insert(yigit.pop());
                }
                if (simdikiAgac->uzunlukGetir() > 0) { // Eğer ağaçta veri varsa listeye ekleyin
                    agaclarListesi.agacEkle(simdikiAgac);
                    simdikiAgac = new IkiliAramaAgaci();
                }
                yigit.push(sayi);
            } else {
                yigit.push(sayi);
            }
        }

        while (!yigit.isEmpty()) {
            simdikiAgac->insert(yigit.pop());
        }

        agaclarListesi.agacEkle(simdikiAgac);

        IkiliAramaAgaci* enYuksekAgac = agaclarListesi.enYuksekAgacGetir();
        enYuksekAgac->postOrderYazdir();
        std::cout << std::endl;
        Sleep(10);
    }

    file.close();
    return 0;
}