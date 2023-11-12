#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(int n, int k) {
    vector<int> combination(k, 0);
    int i = 0;

    while (i >= 0) {
        combination[i]++;
        
        if (combination[i] > n - 1) {
            i--;
        } else if (i == k - 1) {
            // Печать текущего сочетания
            for (int elem : combination) {
                cout << elem << " ";
            }
            cout << endl;
        } else {
            i++;
            combination[i] = combination[i - 1];
        }
    }
}

int main() {
    int n, k;
    cout << "Введите значения n и k: ";
    cin >> n >> k;

    cout << "Все " << k << "-сочетания из множества {0, 1, ..., " << n - 1 << "}:" << endl;
    generateCombinations(n, k);

    return 0;
}