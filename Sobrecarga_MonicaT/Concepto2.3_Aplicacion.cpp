// punto_eq_bug.cpp
#include <iostream>
using namespace std;

class Punto {
public:
    int x, y;
    Punto(int _x, int _y) : x(_x), y(_y) {}
    bool operator==(const Punto& p)const {
        return x == p.x && y == p.y;  // BUG: ¿qué no está bien?
    }
};
int main() {
    Punto _a(3,4), _b(3,4), _c(4,4);
    cout << std::boolalpha;
    cout << (_a == _b) << endl;  // true
    cout << (_a == _c) << endl;  // false

    return 0;
}