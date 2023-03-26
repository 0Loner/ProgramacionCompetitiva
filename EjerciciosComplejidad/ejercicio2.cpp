#include <iostream>         

#include <iomanip>          

using namespace std;        

long float pi = 3.141592653589793; // O(1) - Asignar un valor constante a la variable pi

long float devuelvePi(int n) {     // O(1) - Definir una función que devuelve pi

    cout << setprecision(n + 1);   // O(1) - Configurar el formato de salida para que el número tenga una cantidad fija de decimales

    return pi;                    // O(1) - Devolver el valor constante de pi
}

int main() {                      

    int n;                        // O(1) - Declarar una variable de tipo int

    cout << "Ingresa n" << endl;  // O(1) - Imprimir un mensaje en la consola

    cin >> n;                     // O(1) - Leer un valor de entrada desde la consola y almacenarlo en la variable n

    if (n <= 15) {                // O(1) - Realizar una comparación si el valor ingresado es menor o igual que 15

        cout << devuelvePi(n) << endl;  // O(1) - Imprimir el valor de pi con n decimales

    }

    return 0;                     // O(1) - Devolver un valor 0 al sistema operativo indicando que el programa ha terminado con éxito
}

// La complejidad es 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1   => O(10)  => O(1) 
