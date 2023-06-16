#include "Graph.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class BreathFirstSearch : public Graph {
    
public:
    BreathFirstSearch(int Vertices) : Graph(Vertices){}

    void BFS(int startVertex){
        vector<bool> visited(getVertices(), false);
        queue<int> queue;

        queue.push(startVertex);
        while(!queue.empty()){
            int current_vertex = queue.front();
            queue.pop();
            cout << current_vertex << " ";
            vector<Edge> neighbors = getAdjacencyList()[current_vertex];
            for(Edge neighbor: neighbors){
                int destination = neighbor.getDestination();
                if (!visited[destination]){
                    visited[destination] = true;
                    queue.push(destination);
                }
            }
        }
        cout << endl;
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
    graph.BFS(0);

}
