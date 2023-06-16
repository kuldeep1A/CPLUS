#include<iostream>
#include <vector>
using namespace std;

class Edge{
    int destination;
    int weight;
    public:
        Edge(int destination){
            this->destination = destination;
        }
        Edge(int destination, int weight){
            this->destination = destination;
            this->weight = weight;
        }
};

class Graph{
private:
    int numVertices;
    int weight;
    vector<vector<Edge>> AdjacencyList;
    vector<Edge> Edges;

public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        AdjacencyList.resize(numVertices);
    }
    // undirected or unweighted graph
    void addEdgeU(int source, int destination){
        Edge edge = Edge(destination);
        AdjacencyList[source].push_back(edge);
        edge = Edge(source);
        AdjacencyList[destination].push_back(edge);
    }
    // undirected or weighted graph
    void addEdgeU(int source, int destination, int weight){
        Edge edge = Edge(destination, weight);
        AdjacencyList[source].push_back(edge);
        edge = Edge(source, weight);
        AdjacencyList[destination].push_back(edge);
    }

    // Directed or unweighted Graph
    void addEdge(int source, int destination){
        Edge edge = Edge(destination);
        AdjacencyList[source].push_back(edge);
    }

    // Directed or weighted Graph
    void addEdgeW(int source, int destination, int weight){
        Edge edge = Edge(destination, weight);
        AdjacencyList[source].push_back(edge);
    }

    void printGraph(){
        for (int i = 0; i < numVertices; i++){
            cout << "Vertex " << i << " : "; 
            vector<Edge> neighbors = AdjacencyList[i];
            for(Edge neighbor: neighbors){
                cout << neighbor.destination << " ";
            }
            cout << endl;
        }
    }
};