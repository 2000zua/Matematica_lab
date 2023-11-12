#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для подсчета числа циклов в перестановке
int countCycles(const vector<int>& permutation) {
    vector<bool> visited(permutation.size(), false);
    int cycles = 0;

    for (int i = 0; i < permutation.size(); ++i) {
        if (!visited[i]) {
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = permutation[current];
            }
            cycles++;
        }
    }

    return cycles;
}

int main() {
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    vector<vector<int>> stirlingTriangle(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i) {
        stirlingTriangle[i][0] = 0;
    }

    stirlingTriangle[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            vector<int> permutation;
            for (int k = 0; k < i; ++k) {
                permutation.push_back((k + j - 1) % i);
            }
            stirlingTriangle[i][j] = countCycles(permutation);
        }
    }

    cout << "Треугольник Стирлинга первого рода:" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << stirlingTriangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}