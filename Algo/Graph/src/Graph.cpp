#include <iostream>
#include <vector>
using namespace std;

class Graph
{
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
        for(int i = 0; i < numVertices; i++){
            cout << "Vertex " << i << " :";
            for(int neighbor: AdjacencyList[i]){
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int numVertices = 5;

    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}
