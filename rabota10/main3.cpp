#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для вычисления биномиального коэффициента
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }

    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

// Функция для вычисления номера сочетания
int calculateCombinationNumber(const vector<int>& combination) {
    int n = combination.size();
    int k = combination.back();

    int result = 0;
    for (int i = 0; i < n - 1; ++i) {
        result += binomialCoefficient(combination[i], k - 1);
    }

    return result;
}

// Функция для генерации сочетания по номеру
vector<int> generateCombinationByNumber(int n, int k, int number) {
    vector<int> combination(k);
    for (int i = 0; i < k; ++i) {
        combination[i] = i;
    }

    for (int i = k - 1; i >= 0; --i) {
        while (number >= binomialCoefficient(combination[i], k - 1)) {
            number -= binomialCoefficient(combination[i], k - 1);
            combination[i]++;
        }
    }

    return combination;
}

int main() {
    int n, k;
    cout << "Введите значения n и k: ";
    cin >> n >> k;

    int choice;
    cout << "Выберите действие:" << endl;
    cout << "1. Генерировать сочетание по номеру." << endl;
    cout << "2. Находить номер сочетания." << endl;
    cout << "Введите номер действия: ";
    cin >> choice;

    if (choice == 1) {
        // Генерация сочетания по номеру
        int number;
        cout << "Введите номер сочетания: ";
        cin >> number;

        vector<int> generatedCombination = generateCombinationByNumber(n, k, number);
        cout << "Сгенерированное сочетание: ";
        for (int elem : generatedCombination) {
            cout << elem << " ";
        }
        cout << endl;
    } else if (choice == 2) {
        // Нахождение номера сочетания
        vector<int> combination(k);
        cout << "Введите сочетание размера " << k << ": ";
        for (int i = 0; i < k; ++i) {
            cin >> combination[i];
        }

        // Проверка корректности введённых данных
        sort(combination.begin(), combination.end());
        for (int i = 0; i < k; ++i) {
            if (combination[i] < 0 || combination[i] >= n) {
                cout << "Ошибка: введено некорректное сочетание." << endl;
                return 1;
            }
        }

        int combinationNumber = calculateCombinationNumber(combination);
        cout << "Номер сочетания: " << combinationNumber << endl;
    } else {
        cout << "Ошибка: неверный выбор действия." << endl;
        return 1;
    }

    return 0;
}