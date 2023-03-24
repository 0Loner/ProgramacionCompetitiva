#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num;
    cin >> num;
    cout << fixed << setprecision(3) << setw(7) << num;
    return 0;
}
