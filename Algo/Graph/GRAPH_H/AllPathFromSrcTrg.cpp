#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

class AllPathFromSrcTrg : public Graph{
private:
    vector<string> paths;
public:
    AllPathFromSrcTrg(int Vertices): Graph(Vertices){}

    void dfs(vector<vector<Edge>> graph, vector<bool> visited, string path, int current, int target){
        if (current == target){
            paths.push_back(path);
            return;
        }

        for (int i = 0; i < graph[current].size(); i++){
            Edge edge = graph[current][i];
            if(!visited[edge.getDestination()]){
                visited[current] = true;
                dfs(graph, visited, path + std::to_string(edge.getDestination()), edge.getDestination(), target);
                visited[current] = false;
            }
        }
    }

    vector<string> AllPath(vector<vector<Edge>> graph, int current, int target){
        vector<bool> visited(getVertices(), false);
        dfs(graph, visited, "0", current, target);
        return paths;
    }

};

int main() {
    AllPathFromSrcTrg graph(7);
    graph.addEdgeU(0, 1);
    graph.addEdgeU(0, 2);
    graph.addEdgeU(1, 3);
    graph.addEdgeU(2, 4);
    graph.addEdgeU(3, 4);
    graph.addEdgeU(3, 5);
    graph.addEdgeU(4, 5);
    graph.addEdgeU(5, 6);
    graph.printGraph();

    vector<string> paths = graph.AllPath(graph.getAdjacencyList(), 0, 5);
    for(string path: paths){
        cout << path << " ";
    }
}