#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;

public:
    Graph(int v);
    void addEdge(int v, int w);
    void topologicalSortUtil(int v, bool visited[], stack<int>& stack);
    void topologicalSort();
};

Graph::Graph(int v){
    this->V = v;
    this->adj = new list<int>[this->V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& stack){
    visited[v] = true;

    for (auto i =adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i]){
            topologicalSortUtil(*i, visited, stack);
        }
    }
    stack.push(v);
}

void Graph::topologicalSort(){
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack);
        }
    }
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,0);
    g.addEdge(2,3);
    g.addEdge(3,1);

    cout << "Topological Sort: ";
    g.topologicalSort();
    return 0;
}
