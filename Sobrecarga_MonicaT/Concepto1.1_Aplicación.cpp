#include <iostream>
using namespace std;

class Complejo {
public:
    double re, im;
    Complejo(int x, int y): re(x), im(y) {}
    Complejo operator+(const Complejo& otro){
        return Complejo(re+otro.re, im+otro.im);
    }
};

int main(){
    Complejo a(1.0, 2.0), b(3.0, -1.0);
    Complejo resultado=a+b;
    cout << "Resultado: (" <<resultado.re <<","<<resultado.im << ")"<< endl;
    return 0;

}