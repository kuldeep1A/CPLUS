#include <iostream>
#include <stack>
#include "Graph.h"

using namespace std;

class TopologicalSort
{
public:
    vector<int> TopoSort(Graph graph)
    {
        vector<int> result;
        stack<int> Stack;
        vector<bool> visited(graph.getVertices(), false);

        for (int i = 0; i < graph.getVertices(); i++)
        {
            if (!visited[i])
            {
                dfs_helper(graph, i, visited, Stack);
            }
        }
        cout << "vertex:" << graph.getVertices();
        cout << "stack: " << Stack.size();
        cout << endl;
        while (!Stack.empty())
        {
            result.push_back(Stack.top());
            Stack.pop();
        }
        return result;
    }

private:
    void dfs_helper(Graph graph, int current, vector<bool> &visited, stack<int> &Stack)
    {
        visited[current] = true;

        vector<Edge> neighbors = graph.getAdjacencyList()[current];
        for (Edge neighbor : neighbors)
        {
            if (!visited[neighbor.getDestination()])
            {
                dfs_helper(graph, neighbor.getDestination(), visited, Stack);
            }
        }

        Stack.push(current);
    }
};

int main()
{
    Graph graph(6);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);

    graph.printGraph();

    TopologicalSort sort;

    vector<int> res = sort.TopoSort(graph);
    for (int ver : res)
    {
        cout << ver << " ";
    }
}