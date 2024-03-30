/** 
* @file main.cpp
* @description Bu dosya programin main fonksiyonunu icerir.
* @course 1.Ogretim B Grubu
* @assignment 1.Odev
* @date 22 July 2023
* @author O.Emre Turhan (osman.turhan@ogr.sakarya.edu.tr), Mahmud Emre Baspehlivan
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "Dugum.hpp"
#include "DugumBaglanti.hpp"

int main(int argc, char** argv) {

    if (argc != 2) {
        std::cerr << "Kullanım: " << argv[0] << " <dosya_adi>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string line;
    DugumBaglanti* lineHead = nullptr;
    DugumBaglanti* lineTail = nullptr;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;

        DugumBaglanti* newLine = new DugumBaglanti();

        // Yazdırma işlevi için iki string tanımlıyoruz.
        //std::string onlarOutput = "";
        //std::string birlerOutput = "";

        while (iss >> number) {
            int onlar = number / 10;
            int birler = number % 10;

            BagliListeyeEkle(newLine->onlarList, onlar);
            BagliListeyeEkle(newLine->birlerList, birler);

            // Rakamları string'e ekliyoruz.
            //onlarOutput += std::to_string(onlar) + " ";
            //birlerOutput += std::to_string(birler) + " ";
        }

        // Her satırın sonunda onlar ve birler basamakları için bilgileri yazdırıyoruz.
        //std::cout << onlarOutput << " " << birlerOutput << std::endl;

        if (!lineHead) {
            lineHead = newLine;
            lineTail = newLine;
        } else {
            lineTail->next = newLine;
            lineTail = newLine;
        }
    }
    file.close();


    int onlarIndex, birlerIndex;

    std::cout << "\n" << "Konum A: ";
    std::cin >> onlarIndex;

    std::cout << "Konum B: ";
    std::cin >> birlerIndex;

    IndexIleBagliListeDegistir(lineHead, onlarIndex, birlerIndex);

    double onlarTotalAverage = 0.0;
    double birlerTotalAverage = 0.0;

    int index = 0;
    bool canContinue = true;
    while (canContinue) {
        canContinue = false;  // Eğer bu indekste hiç veri kalmadıysa döngüyü sonlandır.

        double onlarSum = 0.0;
        int onlarCount = 0;

        double birlerSum = 0.0;
        int birlerCount = 0;

        DugumBaglanti* currentLine = lineHead;
        while (currentLine) {
            Dugum* onlarDugum = currentLine->onlarList;
            Dugum* birlerDugum = currentLine->birlerList;

            for (int i = 0; i < index && onlarDugum; ++i) {
                onlarDugum = onlarDugum->next;
            }
            for (int i = 0; i < index && birlerDugum; ++i) {
                birlerDugum = birlerDugum->next;
            }

            if (onlarDugum) {
                canContinue = true;
                onlarSum += onlarDugum->data;
                onlarCount++;
            }

            if (birlerDugum) {
                canContinue = true;
                birlerSum += birlerDugum->data;
                birlerCount++;
            }

            currentLine = currentLine->next;
        }

        if (onlarCount != 0) {
            onlarTotalAverage += onlarSum / onlarCount;
        }
        if (birlerCount != 0) {
            birlerTotalAverage += birlerSum / birlerCount;
        }

        index++;
    }

    std::cout << "\n" << "Ust: " << onlarTotalAverage << std::endl;
    std::cout << "Alt: " << birlerTotalAverage << std::endl;

    while (lineHead) {
        DugumBaglanti* temp = lineHead;
        lineHead = lineHead->next;
        delete temp;
    }

    return 0;
}