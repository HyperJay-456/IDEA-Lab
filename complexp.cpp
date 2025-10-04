#include <iostream>
using namespace std;

class Complex {
    float real, imag;

    public:
    void setDt(float r, float i) {
        real = r;
        imag = i;
    }
    
    void display() {
        cout << "Real: " << real << ", Imaginery: " << imag << endl;
    }

    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

class Animal {
    public: 
    virtual void sound() {
        cout << "Animal Makes A Sound. \n" << endl;
    }
};

class dog : public Animal {
    void sound() override {
        cout << "Dog Barks." << endl;
    }
};

class Base { 
public: 
virtual void show() { 
cout << "Base class show function" << endl; 
} 
};

class Box {
    private:
    int length;
    public: 
    Box() : length(0) {}
    friend void setLen(Box &b, int len);
};

void setLen(Box &b, int len) {
    b.length = len;
    cout << "Length Set To: " << b.length << endl;
};

int main () {
    Complex c1, c2, result;
    c1.setDt(2.5, 3.5);
    c2.setDt(1.5, 2.5);
    result = c1.add(c2);
    cout << "Sum of Complex Numbers: ";
    result.display();
    Base b;
    b.show();
    Animal* a;
    dog d;
    a = &d;
    a -> sound();
    Box b1;
    setLen(b1, 26);
    return 0;
}