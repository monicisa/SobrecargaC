// punto_eq.cpp
#include <iostream>
using namespace std;

class Punto {
public:
    int x, y;
    Punto(int _x, int _y) : x(_x), y(_y) {}
    bool operator==(const Punto& p) {
         return x==p.x && y==p.y;
        // COMPLETA: devuelve true si los dos puntos son iguales
    }
};

int main() {
    Punto a(3,4), b(3,4), c(4,4);
    cout << std::boolalpha;
    cout << (a == b) << endl;  // true
    cout << (a == c) << endl;  // false
}