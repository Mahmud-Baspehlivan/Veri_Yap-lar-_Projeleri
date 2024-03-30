#ifndef YIGIT_HPP
#define YIGIT_HPP

#include <iostream>

class Yigit {
private:
    int* veri;
    int top;
    int kapasite;

public:
    Yigit();

    void push(int deger);
    
    int pop();

    bool isEmpty() const;

    int topDeger() const;

    ~Yigit();
};

#endif // YIGIT_HPP
