#include <iostream>
#include <list>
#include <stack>

using namespace std;
class Graph{
    public:
        int V; 
        Graph(int V);
        list<int>* adj;
        void tipologicalSortUtil(int v, bool visited[], stack<int>& Stack);
        void addEdge(int v, int w);
        void topologicalSort();
    };

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::tipologicalSortUtil(int v, bool visited[], stack<int>& Stack){
    visited[v] = true;
    list<int>::iterator i;
    for ( i = adj[v].begin(); i != adj[v].end(); i++){
        if (!visited[*i])
        {
            tipologicalSortUtil(*i, visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalSort(){
    stack<int> Stack;

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    for (int i = 0; i < V; i++){
        if (visited[i] == false){
            tipologicalSortUtil(i, visited, Stack);
        }
    }

    while (Stack.empty() == false){
        cout << Stack.top() << " ";
        Stack.pop();
    }

}

int main()
{
    int a, b, n, opc;

    cout << "Введите количество элементов в множестве (n): ";
    cin >> n;

    Graph g(n);

    cout << "Введите пары a b, соответвующие неравенствам a < b: \n";
    cin >>a>>b;
    g.addEdge(a, b);
    cout << "Following is a Topological Sort of the given graph: ";
    g.topologicalSort();
            
    return 0;
}


