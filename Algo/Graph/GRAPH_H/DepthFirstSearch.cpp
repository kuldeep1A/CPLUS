#include "Graph.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class DepthFirstSearch: public Graph{
public:
    DepthFirstSearch(int Vertices) : Graph(Vertices){}

    void DFS(int startVertex){
        vector<bool> visited(getVertices(), false);
        stack<int> stack;

        visited[startVertex] = true;
        stack.push(startVertex);
        while(!stack.empty()){
            int current_vertex = stack.top();
            cout << current_vertex << " ";

            stack.pop();
            vector<Edge> neighbors = getAdjacencyList()[current_vertex];
            for (Edge neighbor: neighbors){
                int destination = neighbor.getDestination();
                if (!visited[destination]){
                    visited[destination] = true;
                    stack.push(destination);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    DepthFirstSearch graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.printGraph();
    graph.DFS(0);

}