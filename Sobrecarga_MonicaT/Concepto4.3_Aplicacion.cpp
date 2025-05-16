#include <iostream>
using namespace std;

class Contador {
    int valor;
public:
    Contador(int v) : valor(v) {}

    Contador operator++(int) {
        Contador temp = *this;  
        valor++;                
        return temp;           
    }

    int get() const { return valor; }
};

int main() {
    Contador cnt(7);
    Contador old = cnt++;
    cout << "Old: " << old.get() << ", New: " << cnt.get() << endl;
}
