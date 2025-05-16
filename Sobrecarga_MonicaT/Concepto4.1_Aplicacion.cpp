#include <iostream>
using namespace std;

class Contador {
private:
    int valor;
public:
    Contador(int v) : valor(v) {}

    // Sobrecarga del post-incremento (cnt++)
    Contador operator++(int) {
        Contador temp = *this; // copia original
        valor++;               // incrementa el actual
        return temp;           // devuelve la copia
    }

    int get() const { return valor; }
};

int main() {
    Contador cnt(7);
    Contador old = cnt++;
    cout << "Old: " << old.get() << ", New: " << cnt.get() << endl;
}
