#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class PartialOrder {
    int n;
    vector<vector<int>> adj;

public:
    PartialOrder(int n);
    void addRelation(int a, int b);
    vector<int> linearExtension();
};

PartialOrder::PartialOrder(int n) {
    this->n = n;
    adj.resize(n);
}

void PartialOrder::addRelation(int a, int b) {
    adj[a].push_back(b);
}

vector<int> PartialOrder::linearExtension() {
    vector<int> inDegree(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            ++inDegree[j];
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            --inDegree[v];
            if (inDegree[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (result.size() != n) {
        cout << "Ordem parcial incorreta. Nao ha elemento minimo" << endl;
        return vector<int>();
    }

    return result;
}

int main() {
    int n, m;
    cout << "Digite o numero de elemento do conjunto n: ";
    cin >> n;

    PartialOrder partialOrder(n);

    cout << "Digite o numero de desigualdades m: ";
    cin >> m;

    cout << "Digite a desigualdade no formato 'a b', aonde a ?< b:" << endl;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        partialOrder.addRelation(a - 1, b - 1); 
    }

    vector<int> linearOrder = partialOrder.linearExtension();

    if (!linearOrder.empty()) {
        cout << "Expansao linear de ordem parcial:" << endl;
        for (int element : linearOrder) {
            cout << element + 1 << " "; 
        }
        cout << endl;
    }
    return 0;
}