#include<iostream>
#include <vector>
using namespace std;

class Graph{
private:
    int numVertices;
    vector<vector<int>> AdjacencyList;

public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        AdjacencyList.resize(numVertices);
    }
    void addEdge(int source, int destination){
        AdjacencyList[source].push_back(destination);
        AdjacencyList[destination].push_back(source);
    }

    void printGraph(){
        for (int i = 0; i < numVertices; i++){
            cout << "Vertex " << i << " : "; 
            vector<int> neighbors = AdjacencyList[i];
            for(int neighbor: neighbors){
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};