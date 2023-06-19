#include "Graph.h"
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

class BreathFirstSearch : public Graph {
    
public:
    BreathFirstSearch(int Vertices) : Graph(Vertices){}

    vector<int> BFS(int startVertex)
    {
        unordered_set<int> visited;
        queue<int> queue;
        vector<int> traversal_order;

        queue.push(startVertex);
        while(!queue.empty()){
            int current_vertex = queue.front();
            queue.pop();
            if (visited.find(current_vertex) == visited.end())
            {
                visited.insert(current_vertex);
                traversal_order.push_back(current_vertex);

                vector<Edge> neighbors = getAdjacencyList()[current_vertex];
                for (Edge neighbor : neighbors)
                {
                    int destination = neighbor.getDestination();
                    if (visited.find(destination) == visited.end())
                    {
                        queue.push(destination);
                    }
                }
            }
        }
        return traversal_order;
    }
};


int main() {
    BreathFirstSearch graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.printGraph();
    vector<int> res = graph.BFS(0);
    cout << "BFS: ";
    for (int ver : res)
    {
        cout << ver << " ";
    }
}
