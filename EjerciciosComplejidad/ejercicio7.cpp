#include <iostream>     //El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo
#include <algorithm>    //El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo

int main() //O(1)
{
    std::string letters = "ABCDEFGHIJ";//O(1).
    //_____________________________________________________________________
    do {
        std::cout << letters << std::endl;
    } while (std::next_permutation(letters.begin(), letters.end()));
    /*
    Este es el ciclo principal del programa. La salida en consola de la cadena "letters" es constante y tiene una complejidad de O(1). 
    La función "std::next_permutation()" se llama en el bucle y tiene una complejidad de O(n), donde n es el tamaño de la cadena "letters".
    La función se llama hasta que se agoten todas las permutaciones, lo que lleva una complejidad de O(n!) en el peor caso.
    Por lo tanto, la complejidad total de este bucle es de O(n * n!), donde n es el tamaño de la cadena "letters".
    */

    return 0;//O(1).
}
// la complejidad total de este algoritmo es de O(n * n!), donde n es el tamaño de la cadena "letters".