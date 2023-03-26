#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertBase(string num, int X, int Y) {
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = num.size();
    long long decimal = 0, power = 1;
    for (int i = n - 1; i >= 0; i--) {
        int digit = digits.find(num[i]);
        decimal += digit * power;
        power *= X;
    }
    string result = "";
    while (decimal > 0) {
        int digit = decimal % Y;
        result += digits[digit];
        decimal /= Y;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num = "FF";
    int X = 16, Y = 10;
    string result = convertBase(num, X, Y);
    cout << num << " in base " << X << " is " << result << " in base " << Y << endl;
    return 0;
}


//T(n, X, Y) = O(n) + O(log(XY))