#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введите количество строк треугольника: ";
    cin >> n;

    vector<vector<int>> stirlingTriangle(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i) {
        stirlingTriangle[i][0] = 0;
    }

    stirlingTriangle[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            stirlingTriangle[i][j] = j * stirlingTriangle[i - 1][j] + stirlingTriangle[i - 1][j - 1];
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