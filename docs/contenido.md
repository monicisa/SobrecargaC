# Sobrecarga de Operadores en C++

Este recurso de aprendizaje ofrece una guía completa para comprender y aplicar la **sobrecarga de operadores en C++**, abarcando desde lo básico hasta conceptos avanzados. Cada sección incluye definición, sintaxis, casos de uso, errores comunes y ejemplos funcionales.

---

## Niveles de Aprendizaje

### 🟢 Nivel Básico

#### 1. Sobrecarga de Operadores Binarios
- **Definición**: Permite redefinir operadores como +, -, *, etc., para que funcionen con objetos de una clase definida por el usuario.
- **Sintaxis**:
```cpp
Tipo operator+(const Clase& otro);
```
- **Casos de uso**: Sumar objetos como puntos, vectores o unidades.
- **Errores comunes**:
  - No devolver un nuevo objeto.
  - No declarar correctamente los parámetros como `const`.
- **Ejemplo**: `ejemplo1.cpp`[ejemplos/ejemplo1.cpp]

#### 2. Sobrecarga del operador `==`
- **Definición**: Compara si dos objetos tienen el mismo estado.
- **Sintaxis**:
```cpp
bool operator==(const Clase& otro);
```
- **Casos de uso**: Comparar clases como libros, usuarios, etc.
- **Errores comunes**:
  - Comparar punteros en lugar de contenido.
- **Ejemplo**: `ejemplo2.cpp`

#### 3. Sobrecarga de `<<` (salida)
- **Definición**: Permite imprimir objetos con `cout` de forma personalizada.
- **Sintaxis**:
```cpp
friend ostream& operator<<(ostream& os, const Clase& obj);
```
- **Casos de uso**: Mostrar objetos de forma legible.
- **Errores comunes**:
  - Olvidar usar `friend`.
- **Ejemplo**: `ejemplo3.cpp`

---

### 🟡 Nivel Intermedio

#### 4. Sobrecarga del operador `++` (postfijo)
- **Definición**: Define cómo incrementar un objeto de manera personalizada.
- **Sintaxis**:
```cpp
Clase operator++(int);
```
- **Casos de uso**: Contadores, iteradores.
- **Errores comunes**:
  - Confundir pre y post incremento.
- **Ejemplo**: `ejemplo4.cpp`

#### 5. Sobrecarga del operador de asignación `=`
- **Definición**: Controla cómo se copian los objetos, especialmente cuando se usan recursos dinámicos.
- **Sintaxis**:
```cpp
Clase& operator=(const Clase& otra);
```
- **Casos de uso**: Clases con punteros o recursos que deben duplicarse.
- **Errores comunes**:
  - No liberar memoria previa.
  - No manejar autoasignación.
- **Ejemplo**: `ejemplo5.cpp`

---

### 🔴 Nivel Avanzado

#### 6. Conversión de tipo a primitivo
- **Definición**: Permite convertir un objeto a un tipo básico.
- **Sintaxis**:
```cpp
operator tipo() const;
```
- **Casos de uso**: Convertir clases como temperatura, moneda o peso.
- **Errores comunes**:
  - Hacer conversiones implícitas peligrosas.
- **Ejemplo**: `ejemplo6.cpp`

---

## Caso real relacionado

En los años 90, el equipo de desarrollo de **Adobe Photoshop** tuvo que rediseñar su sistema de representación de puntos y vectores para mejorar el rendimiento del motor gráfico. La sobrecarga de operadores como `+`, `-` y `*` les permitió hacer que las operaciones matemáticas en objetos como `Pixel`, `Color` y `Vector2D` fueran más naturales, legibles y reutilizables, acelerando el desarrollo y depuración del software.

---

## Cómo usar este recurso

1. Explora el directorio `ejemplos/`.
2. Compila los archivos con `g++ ejemploX.cpp -o ejemploX`
3. Ejecuta cada ejemplo y analiza su salida.

---

## Etiquetas del Repositorio

- `C++`
- `operadores`
- `sobrecarga`
- `educativo`
- `ejemplos`
- `POO`
- `nivel-básico`
- `nivel-avanzado`

---

## Licencia

Este recurso está publicado bajo la Licencia MIT.
