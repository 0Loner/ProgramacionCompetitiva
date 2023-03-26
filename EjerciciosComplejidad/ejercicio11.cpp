#include <iostream>
#include <cmath>
using namespace std;

bool esPrimo(long long num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long X;
    cin >> X;
    if (esPrimo(X)) {
        cout << "Primo" << endl;
    } else {
        cout << "Compuesto" << endl;
    }
    return 0;
}

O(sqrt(X))
