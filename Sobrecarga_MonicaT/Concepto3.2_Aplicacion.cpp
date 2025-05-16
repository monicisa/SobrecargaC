// empleado_io.cpp
#include <iostream>
using namespace std;

class Empleado {
public:
    string nombre;
    int id;
    Empleado(string n, int i) : nombre(n), id(i) {}
    // COMPLETA: declara friend operator<<
    
    friend ostream& operator<<(ostream& os, const Empleado& e);
};

ostream& operator<<(ostream& os, const Empleado& e) {
    os << "Empleado[" << e.id << "]: " << e.nombre;
    return os;
}



int main() {
    Empleado e("Ana", 101);
    cout << e << endl;  // Empleado[101]: Ana
    return 0;
}