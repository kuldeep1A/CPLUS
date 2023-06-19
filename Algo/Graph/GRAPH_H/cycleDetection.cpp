#include <iostream>
#include <unordered_set>
#include "Graph.h"

using namespace std;

class cycleDetection
{
public:
    bool isCycle(Graph graph)
    {
        unordered_set<int> visited;
        unordered_set<int> recursionStack;

        for (int i = 0; i < graph.getVertices(); i++)
        {
            if (isCycleUtil(graph, i, visited, recursionStack))
            {
                return true;
            }
        }
        return false;
    }

private:
    bool isCycleUtil(Graph graph, int vertex, unordered_set<int> &visited, unordered_set<int> &recursionStack)
    {
        visited.insert(vertex);
        recursionStack.insert(vertex);

        vector<Edge> neighbors = graph.getAdjacencyList()[vertex];
        for (Edge neighbor : neighbors)
        {
            if (recursionStack.count(neighbor.getDestination()) || !visited.count(neighbor.getDestination()) && isCycleUtil(graph, neighbor.getDestination(), visited, recursionStack))
            {
                return true;
            }
        }

        recursionStack.erase(vertex);
        return false;
    }
};

int main()
{
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    cycleDetection myObj;

    bool res = myObj.isCycle(graph);

    cout << (res ? "true" : "false");
    return 0;
}