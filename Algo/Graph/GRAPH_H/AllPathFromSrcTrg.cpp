#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

class AllPathFromSrcTrg : public Graph{
private:
    vector<string> paths;
public:
    AllPathFromSrcTrg(int Vertices): Graph(Vertices){}

    vector<vector<int>> AllPath(int current, int target)
    {
        vector<vector<int>> paths;
        vector<bool> visited(getVertices(), false);
        vector<int> path;
        dfs_helper(current, target, visited, path, paths);
        return paths;
    }
    void dfs_helper(int current, int target, vector<bool> &visited, vector<int> &path, vector<vector<int>> &paths)
    {
        visited[current] = true;
        path.push_back(current);

        if (current == target){
            paths.push_back(path);
        }
        else
        {
            vector<Edge> neighbors = getAdjacencyList()[current];
            for (Edge neighbor : neighbors)
            {
                if (!visited[neighbor.getDestination()])
                {
                    dfs_helper(neighbor.getDestination(), target, visited, path, paths);
                }
            }
        }
        path.pop_back();
        visited[current] = false;
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

    vector<vector<int>> paths = graph.AllPath(0, 5);
    cout << "All paths from " << 0 << " to " << 5 << ":" << endl;
    for (const vector<int> &path : paths)
    {
        for (int vertex : path)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }
}