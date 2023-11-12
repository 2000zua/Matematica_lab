#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления знака перестановки
int calculateSign(const vector<int>& permutation) {
    int sign = 1;
    int n = permutation.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (permutation[i] > permutation[j]) {
                sign *= -1;
            }
        }
    }

    return sign;
}

// Функция для генерации всех перестановок и вывода их знаков
void generatePermutations(int n, vector<int>& permutation, vector<bool>& used) {
    if (permutation.size() == n) {
        // Перестановка сгенерирована, выводим её и знак
        for (int elem : permutation) {
            cout << elem << " ";
        }

        int sign = calculateSign(permutation);
        cout << " (знак: " << sign << ")" << endl;

        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            permutation.push_back(i);

            generatePermutations(n, permutation, used);

            used[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    vector<int> permutation;
    vector<bool> used(n + 1, false);

    cout << "Все перестановки множества {1, ..., " << n << "} и их знаки:" << endl;
    generatePermutations(n, permutation, used);

    return 0;
}