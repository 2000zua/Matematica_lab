#include <iostream>
#include <vector>

using namespace std;

void generatePartitions(int n, vector<vector<int>>& partitions, vector<int>& current, int index) {
    if (n == 0) {
        partitions.push_back(current);
        return;
    }

    for (int i = index; i <= n; ++i) {
        current.push_back(i);
        generatePartitions(n - i, partitions, current, i);
        current.pop_back();
    }
}

int main() {
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    vector<vector<int>> partitions;
    vector<int> current;

    generatePartitions(n, partitions, current, 1);

    cout << "Все разбиения множества {1, 2, ..., " << n << "}:" << endl;
    for (const vector<int>& partition : partitions) {
        for (int elem : partition) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}