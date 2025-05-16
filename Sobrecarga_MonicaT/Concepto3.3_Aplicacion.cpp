#include <iostream>
using namespace std;

class Empleado {
    string nombre;
    int id;
public:
    Empleado(string n, int i) : nombre(n), id(i) {}

    // Corrección: devuelve ostream&
    friend ostream& operator<<(ostream& os, const Empleado& e) {
        os << "ID=" << e.id << ", Nombre=" << e.nombre;
        return os;
    }
};

int main() {
    Empleado e1("Ana", 101), e2("Luis", 202);
    cout << e1 << endl;
    cout << e2 << endl;
    return 0;
}
