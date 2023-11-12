#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutations(int n, int k) {
    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        elements[i] = i;
    }

    vector<int> permutation(k, 0);

    do {
        // Печать текущего размещения
        for (int i = 0; i < k; ++i) {
            cout << elements[permutation[i]] << " ";
        }
        cout << endl;
    } while (next_permutation(permutation.begin(), permutation.end()));
}

int main() {
    int n, k;
    cout << "Введите значения n и k: ";
    cin >> n >> k;

    if (k > n) {
        cout << "Ошибка: k не может быть больше n." << endl;
        return 1;
    }

    cout << "Все " << k << "-размещения из множества {0, 1, ..., " << n - 1 << "}:" << endl;
    generatePermutations(n, k);

    return 0;
}