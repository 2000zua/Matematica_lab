#include<iostream>
#include <vector>
#include <stack>

using namespace std;


class Graph{

public:

  int numVertices;
  vector<vector<int>> adjList;  

  Graph(int V) : numVertices(V), adjList(V){};

  void adicionarAresta(int u, int v){
    adjList[u].push_back(v);
  }


};



void DFS(const Graph& G, int v, vector<bool>& visitados, stack<int>& resultado){
  visitados[v] = true;
  
  for (int  w : G.adjList[v])
  {
    if (!visitados[w])
    {
      DFS(G, w, visitados, resultado);
    }
  }
  resultado.push(v);

}


vector<int> ordenacaoTopologica( Graph& G){
  vector<bool> visitados(G.numVertices, false);
  stack<int> resultado;

  for (int v = 0; v < G.numVertices; ++v)
  {
    if (!visitados[v])
    {
      DFS(G, v, visitados, resultado);
    }
  }

  vector<int> ordenacao;
  while (!resultado.empty())
  {
    ordenacao.push_back(resultado.top());
    resultado.pop();
  }
  return ordenacao;
}

