#include <iostream>//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo
#include <vector>//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo

using namespace std;//El tiempo de compilación de estas directivas de preprocesador es constante y no tiene efecto en la complejidad del algoritmo

bool binarySearch(vector<int>& L, int v) {
    int low = 0;//O(1).
    int high = L.size() - 1;//O(1).
    int comparisons = 0;//O(1).
//________________________________________________________
    while (low <= high && comparisons < 20) {
        int mid = (low + high) / 2;
        if (L[mid] == v) {
            return true;
        } else if (L[mid] < v) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        comparisons++;
    }
    /*
    El bucle while se ejecuta mientras low es menor o igual que high y comparisons es menor que 20. Por lo tanto,
    el bucle se ejecutará a lo sumo 20 veces. Cada iteración del bucle lleva a cabo una cantidad constante de trabajo,
     como asignar mid y comparar L[mid] con v. Por lo tanto, el costo total del bucle es O(1) * 20 = O(1).
    */
    //________________________________________________________
    return false;//O(1).
}

int main() {
    vector<int> L = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//O(1).
    int v = 5;//O(1).
    if (binarySearch(L, v)) {//O(1).
        cout << "El valor " << v << " existe en la lista." << endl;//O(1).
    } else {//O(1).
        cout << "El valor " << v << " no existe en la lista." << endl;//O(1).
    }
    return 0;
}

//En general, la complejidad temporal de este algoritmo es O(log n), donde n es el tamaño del vector de entrada.