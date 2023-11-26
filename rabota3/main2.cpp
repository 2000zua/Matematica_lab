#include <iostream>
#include <list>
#include <stack>
#include "Garfo.h"

int main()
{
    int a, b, n, opc;
    cout << "Введите количество элементов в множестве (n): ";
    cin >> n;
    Graph g(n);
    //cout << "Введите пары a b, соответвующие неравенствам.\n";
    cout << "Введите пары a b, соответвующие неравенствам a < b: \n";
    for (int i = 1; i <= n; i++)
    {
        cout << "["<<i<<"]" << " a < b: ";
        cin >>a>>b;
        g.addEdge(a, b);
    }
    //Graph g(n);


    cout << "Following is a Topological Sort of the given graph: ";
    g.topologicalSort();
            
    return 0;
}