#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& L, int v) {
    int low = 0;
    int high = L.size() - 1;
    int comparisons = 0;

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
    return false;
}

int main() {
    vector<int> L = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v = 5;
    if (binarySearch(L, v)) {
        cout << "El valor " << v << " existe en la lista." << endl;
    } else {
        cout << "El valor " << v << " no existe en la lista." << endl;
    }
    return 0;
}