/** 
* @file Yigit.cpp
* @description Bu dosya programin Yigit sinifini ve metodlarini icerir.
* @course 1.Ogretim B Grubu
* @assignment 2.Odev
* @date 05 Aug 2023
* @author O.Emre Turhan (osman.turhan@ogr.sakarya.edu.tr), Mahmud Emre Baspehlivan (emre.baspehlivan@ogr.sakarya.edu.tr)
*/

#include "Yigit.hpp"

Yigit::Yigit() : top(-1), kapasite(100) {
    veri = new int[kapasite];
}

void Yigit::push(int deger) {
    if (top >= kapasite - 1) {
        int* temp = new int[kapasite * 2];
        for (int i = 0; i <= top; ++i) {
            temp[i] = veri[i];
        }
        delete[] veri;
        veri = temp;
        kapasite *= 2;
    }
    veri[++top] = deger;
}

int Yigit::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Yigit bos!");
    }
    return veri[top--];
}

bool Yigit::isEmpty() const {
    return top == -1;
}

int Yigit::topDeger() const {
    if (isEmpty()) {
        throw std::runtime_error("Yigit bos!");
    }
    return veri[top];
}

Yigit::~Yigit() {
    delete[] veri;
}
