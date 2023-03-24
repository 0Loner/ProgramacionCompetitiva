#include <iostream>
#include <iomanip>
using namespace std;


long float pi = 3.141592653589793;

long float devuelvePi(int n) {
    cout<<setprecision(n + 1);
    return pi;
}

int main()
{
    int n;
    cout << "Ingresa n" << endl;
    cin >> n;
    if (n <= 15) {
        cout << devuelvePi(n) << endl;
    }
    return 0;
}
