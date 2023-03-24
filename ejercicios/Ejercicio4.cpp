#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Leer n enteros aleatorios
    int n;
    std::cout << "Ingrese la cantidad de enteros aleatorios: ";
    std::cin >> n;

    std::vector<int> enteros(n);
    std::cout << "Ingrese los enteros aleatorios: ";
    for (int i = 0; i < n; i++) {
        std::cin >> enteros[i];
    }

    // Ordenar el vector
    std::sort(enteros.begin(), enteros.end());

    // Eliminar los elementos duplicados
    auto ultimo = std::unique(enteros.begin(), enteros.end());
    enteros.erase(ultimo, enteros.end());

    // Imprimir los enteros diferentes en orden ascendente
    std::cout << "Los enteros diferentes ordenados son: ";
    for (auto entero : enteros) {
        std::cout << entero << " ";
    }
    std::cout << std::endl;

    return 0;
}
