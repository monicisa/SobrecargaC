#include <iostream>
#include <cstring>  
using namespace std;

class Buffer {
    char* datos;
    size_t n;

public:
    Buffer(const char* texto) {
        n = strlen(texto);
        datos = new char[n + 1];  
        strcpy(datos, texto);
    }


    ~Buffer() {
        delete[] datos;
    }

    
    Buffer(const Buffer& otro) {
        n = otro.n;
        datos = new char[n + 1];
        strcpy(datos, otro.datos);
    }


    Buffer& operator=(const Buffer& otro) {
        if (this != &otro) {  
            delete[] datos;   
            n = otro.n;
            datos = new char[n + 1];
            strcpy(datos, otro.datos);
        }
        return *this;
    }

    
    void mostrar() const {
        cout << datos << endl;
    }
};

int main() {
    Buffer b1("Hola mundo");
    Buffer b2("Otro texto");

    b2 = b1;  

    cout << "Contenido de b1: ";
    b1.mostrar();

    cout << "Contenido de b2: ";
    b2.mostrar();

    return 0;
}
