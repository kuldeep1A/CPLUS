#include <iostream>
#include <vector>
using namespace std;

class Edge {
    int destination;
    int weight = 0;
public:
    Edge(int destination) {
        this->destination = destination;
    }

    Edge(int destination, int weight) {
        this->destination = destination;
        this->weight = weight;
    }

    int getDestination(){
        return destination;
    }
    int getWeight(){
        return weight;
    }
};

class Graph {
private:
    int numVertices;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjacencyList.resize(numVertices);
    }

    void addEdgeU(int source, int destination) {
        Edge edge(destination);
        adjacencyList[source].push_back(edge);
        edge = Edge(source);
        adjacencyList[destination].push_back(edge);
    }

    void addEdgeU(int source, int destination, int weight) {
        Edge edge(destination, weight);
        adjacencyList[source].push_back(edge);
        edge = Edge(source, weight);
        adjacencyList[destination].push_back(edge);
    }

    void addEdge(int source, int destination) {
        Edge edge(destination);
        adjacencyList[source].push_back(edge);
    }

    void addEdgeW(int source, int destination, int weight) {
        Edge edge(destination, weight);
        adjacencyList[source].push_back(edge);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << " -> ";
            vector<Edge> neighbors = adjacencyList[i];
            for (Edge neighbor : neighbors) {
                cout << "(" <<  neighbor.getDestination() << "d, "  << neighbor.getWeight() << "w) ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(6);

    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 4);
    graph.addEdgeU(1, 2);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(2, 3);
    graph.addEdgeU(3, 4);
    graph.addEdgeU(0, 5);

    graph.printGraph();

    return 0;
}
