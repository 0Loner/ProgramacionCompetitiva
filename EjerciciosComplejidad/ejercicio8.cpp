#include <iostream> //El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo
#include <vector> //El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo

using namespace std; //El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo

void generarSubconjuntos(vector<int>& subconjunto, int n, int k) {
    if (k == n+1) { // caso base: ya se han seleccionado los k elementos
        for (int i = 0; i < subconjunto.size(); i++) {
            cout << subconjunto[i] << " ";
        }
        cout << endl;//O(1).
        return;//O(1).
    }
    /*
    La función generarSubconjuntos tiene dos llamadas recursivas, una con k+1 y otra con k+1 y un elemento añadido,
    lo que implica que la complejidad es de O(2^n).
    */

//___________________________________________________
    subconjunto.push_back(k);
    generarSubconjuntos(subconjunto, n, k+1);
    subconjunto.pop_back();
    generarSubconjuntos(subconjunto, n, k+1);
    //______________________________________________
    /*
    La impresión de los subconjuntos se realiza en un bucle que recorre todos los elementos del subconjunto,
     por lo que la complejidad es O(n), donde n es el número de elementos del subconjunto.
    */
}

int main() {
    vector<int> subconjunto;//O(1).
    generarSubconjuntos(subconjunto, 20, 1);//O(1).
    return 0;
}
/*
La llamada a la función generarSubconjuntos también es O(2^n), ya que la complejidad de la función depende de la complejidad de las llamadas recursivas.
En resumen, la complejidad del algoritmo es O(2^n * n).
*/