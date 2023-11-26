/**
 * Trabalho de trabalho numero 2
 * Alagaritimo de classificacao de topologia
*/

#include <iostream>
#include <list>
#include <stack>
#include "Graph.h"

using namespace std;


int main()
{
    int a, b, n;

    cout << "Введите количество элементов в множестве (n): ";
    cin >> n;
    Graph g(n);
    
    cout << "Введите пары a b, соответвующие неравенствам  a < b.\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "["<<i<<"]: ";
        cin >>a>>b;
        g.adicionarAresta(b, a);
    }
    
    vector<int> resultado = ordenacaoTopologica(g);

    cout << "Ordenacao Topologiaca: \n";
    /*
    for (int i : resultado)
    {
        cout << i << " ";
    }*/
    for (int i = resultado.size() - 1; i >= 0; i--)
    {
       cout << resultado[i] << " ";
    }
    
    cout << endl;
    

    return 0;
}


