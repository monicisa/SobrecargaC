# Ejercicios: Sobrecarga de Operadores en C++

Este documento propone ejercicios para practicar la sobrecarga de operadores en C++, divididos en **Nivel Básico** e **Intermedio**. Para cada concepto se incluyen:

1. **Aplicación directa**: implementa el comportamiento desde cero.  
2. **Completación de código**: rellena los espacios marcados.  
3. **Detección y corrección de errores**: encuentra y corrige el bug en la implementación dada.  

---

## 🟢 Nivel Básico

### Concepto 1: Operador binario `+`

1. **Aplicación directa**  
   - Implementa una clase `Vector2D` con atributos `x, y` y sobrecarga el operador `+` para sumar dos vectores.  
   - Prueba en `main()` sumando `(1,2)` + `(3,4)` y muestra el resultado.

2. **Completación de código**  
   ```cpp
   // vector_suma.cpp
   #include <iostream>
   using namespace std;
   
   class Vector2D {
   public:
       double x, y;
       Vector2D(double _x, double _y) : x(_x), y(_y) {}
       
       Vector2D operator+(const Vector2D& v) {
           // COMPLETA: devolver la suma de *this y v
       }
   };
   
   int main() {
       Vector2D a(0.5, 1.5), b(2.0, 3.0);
       Vector2D c = a + b;
       cout << "c = (" << c.x << ", " << c.y << ")" << endl;
       return 0;
   }
   ```

3. **Detección y corrección de errores**  
   ```cpp
   // vector_bug.cpp
   #include <iostream>
   using namespace std;
   
   class Vector2D {
   public:
       double x, y;
       Vector2D(double _x, double _y) : x(_x), y(_y) {}
       Vector2D operator+(Vector2D v) {   // BUG: ¿qué falta aquí?
           Vector2D res;
           res.x = x + v.x;
           res.y = y + v.y;
           return res;
       }
   };
   
   int main() {
       Vector2D v1(1,1), v2(2,2);
       Vector2D v3 = v1 + v2;
       cout << "(" << v3.x << "," << v3.y << ")" << endl;
   }
   ```
   - **Error a corregir**: Falta constructor por defecto y debería pasar por referencia const.

---

### Concepto 2: Operador de comparación `==`

1. **Aplicación directa**  
   - Crea una clase `Punto` con `int x, y` y sobrecarga `operator==`.  
   - En `main()`, compara `(5,5)` con `(5,5)` y `(5,6)`.

2. **Completación de código**  
   ```cpp
   // punto_eq.cpp
   #include <iostream>
   using namespace std;
   
   class Punto {
   public:
       int x, y;
       Punto(int _x, int _y) : x(_x), y(_y) {}
       bool operator==(const Punto& p) {
           // COMPLETA: devuelve true si los dos puntos son iguales
       }
   };
   
   int main() {
       Punto a(3,4), b(3,4), c(4,4);
       cout << std::boolalpha;
       cout << (a == b) << endl;  // true
       cout << (a == c) << endl;  // false
   }
   ```

3. **Detección y corrección de errores**  
   ```cpp
   // punto_eq_bug.cpp
   #include <iostream>
   using namespace std;
   
   class Punto {
   public:
       int x, y;
       Punto(int _x, int _y) : x(_x), y(_y) {}
       bool operator==(Punto p) {
           return x == p.x && y = p.y;  // BUG: ¿qué no está bien?
       }
   };
   ```
   - **Error a corregir**: Uso de asignación en lugar de comparación, y debería recibir `const Punto&`.

---

### Concepto 3: Operadores de E/S (`<<` / `>>`)

1. **Aplicación directa**  
   - Define una clase `Empleado` con `string nombre; int id;` y sobrecarga `operator<<` para imprimir `"Empleado[id]: nombre"`.  
   - En `main()`, crea y muestra dos empleados.

2. **Completación de código**  
   ```cpp
   // empleado_io.cpp
   #include <iostream>
   using namespace std;
   
   class Empleado {
   public:
       string nombre;
       int id;
       Empleado(string n, int i) : nombre(n), id(i) {}
       // COMPLETA: declara friend operator<<
   };
   
   int main() {
       Empleado e("Ana", 101);
       cout << e << endl;  // Empleado[101]: Ana
       return 0;
   }
   ```

3. **Detección y corrección de errores**  
   ```cpp
   // empleado_io_bug.cpp
   #include <iostream>
   using namespace std;
   
   class Empleado {
       string nombre;
       int id;
   public:
       Empleado(string n, int i) : nombre(n), id(i) {}
       friend ostream operator<<(ostream& os, const Empleado& e) {
           os << "ID=" << e.id << ", Nombre=" << e.nombre;
           return os;
       }
   };
   ```
   - **Error a corregir**: `operator<<` debe devolver `ostream&`, no `ostream`.

---

## 🟡 Nivel Intermedio

### Concepto 4: Operador unario post-incremento `operator++(int)`

1. **Aplicación directa**  
   - Implementa clase `Contador` con atributo `int c`, constructor y sobrecarga `operator++(int)` que retorna valor previo.  
   - En `main()`, muestra resultado de `c++` y luego el valor actual.

2. **Completación de código**  
   ```cpp
   // contador_inc.cpp
   #include <iostream>
   using namespace std;
   
   class Contador {
   private:
       int valor;
   public:
       Contador(int v) : valor(v) {}
       Contador operator++(int) {
           // COMPLETA: guarda copia, incrementa valor y devuelve copia
       }
       int get() const { return valor; }
   };
   
   int main() {
       Contador cnt(7);
       Contador old = cnt++;
       cout << "Old: " << old.get() << ", New: " << cnt.get() << endl;
   }
   ```

3. **Detección y corrección de errores**  
   ```cpp
   // contador_inc_bug.cpp
   #include <iostream>
   using namespace std;
   
   class Contador {
       int valor;
   public:
       Contador(int v) : valor(v) {}
       Contador operator++(int) {
           valor++;
           return *this;  // BUG: ¿qué comportamiento falla?
       }
   };
   ```
   - **Error a corregir**: No preservar el valor anterior al incremento.

---

### Concepto 5: Operador de asignación `=`

1. **Aplicación directa**  
   - Crea clase `Buffer` con `char* datos` y `size_t n`, reserva memoria en el constructor, define destructor, y sobrecarga `operator=` para copia profunda.  
   - En `main()`, asigna un buffer a otro y muestra contenido.

2. **Completación de código**  
   ```cpp
   // buffer_asign.cpp
   #include <iostream>
   #include <cstring>
   using namespace std;
   
   class Buffer {
       char* datos;
       size_t n;
   public:
       Buffer(const char* s) {
           n = strlen(s);
           datos = new char[n+1];
           strcpy(datos, s);
       }
       ~Buffer() { delete[] datos; }
       Buffer& operator=(const Buffer& otro) {
           // COMPLETA: evita autoasignación, libera y duplica datos
           return *this;
       }
       void print() const { cout << datos << endl; }
   };
   
   int main() {
       Buffer b1("Hola"), b2("Mundo");
       b1 = b2;
       b1.print();  // Mundo
   }
   ```

3. **Detección y corrección de errores**  
   ```cpp
   // buffer_asign_bug.cpp
   #include <iostream>
   #include <cstring>
   using namespace std;
   
   class Buffer {
       char* datos;
   public:
       Buffer(const char* s) {
           datos = new char[strlen(s)+1];
           strcpy(datos, s);
       }
       ~Buffer() { delete[] datos; }
       Buffer& operator=(const Buffer& otro) {
           delete[] datos;
           datos = otro.datos;   // BUG: ¿qué problema surge aquí?
           return *this;
       }
   };
   ```
   - **Error a corregir**: Asignación de puntero en lugar de duplicación (copia superficial).
