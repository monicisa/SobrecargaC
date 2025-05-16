#include <iostream>
using namespace std;

class Empleado{
public:
    string nombre;
    int id;
    Empleado(string n, int i): nombre(n), id(i){}
    friend ostream& operator<<(ostream& os, const Empleado& e);
};

ostream& operator<<(ostream& os, const Empleado& e){
    os<<"Empleado["<<e.id<<"]: "<<e.nombre;
    return os;
}

int main() {
    Empleado e1("David", 004);
    Empleado e2("Monicisa", 301);

    cout << e1 << endl;  
    cout << e2 << endl;  

    return 0;
}