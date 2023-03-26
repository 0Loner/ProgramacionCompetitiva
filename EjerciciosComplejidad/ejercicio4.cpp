#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Leer n enteros aleatorios O(1)
    int n;
    std::cout << "Ingrese la cantidad de enteros aleatorios: ";
    std::cin >> n;

    std::vector<int> enteros(n); //Crear un vector de tamaño n: O(1)
    std::cout << "Ingrese los enteros aleatorios: ";
    for (int i = 0; i < n; i++) { //Leer los n enteros aleatorios: O(n)
        std::cin >> enteros[i];
    }

    // Ordenar el vector
    std::sort(enteros.begin(), enteros.end()); //Ordenar el vector: O(n log n)

    // Eliminar los elementos duplicados
    auto ultimo = std::unique(enteros.begin(), enteros.end()); //Eliminar los elementos duplicados: O(n)
    enteros.erase(ultimo, enteros.end());

    // Imprimir los enteros diferentes en orden ascendente
    std::cout << "Los enteros diferentes ordenados son: ";
    for (auto entero : enteros) { //Imprimir los enteros diferentes en orden ascendente: O(n)
        std::cout << entero << " ";
    }
    std::cout << std::endl;

    return 0;
}

//Complejidad => O(1) + O(n) + O(n log n) + O(n) + O(n)  => O(nlogn)
