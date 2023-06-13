import java.util.ArrayList;
import java.util.List;


// Types of graph implementation
// adjacency matrix
// edge list
// implicit graph
class Graph1 {
    private final int numVertices;
    private final List<List<Integer>> adjacencyList;

    public Graph1(int numVertices){
        this.numVertices = numVertices;
        adjacencyList = new ArrayList<>(numVertices);

        for(int i = 0; i < numVertices; i++){
            adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int source, int destination){
        adjacencyList.get(source).add(destination);
    }

    public void printGraph(){
        for(int i = 0; i < numVertices; i++){
            System.out.print("Vertex " + i + " is connected to: ");
            for(Integer neighbor: adjacencyList.get(i)){
                System.out.print(neighbor + " ");
            }
            System.out.println();
        }
    }
}

public class GraphMain{
    public static void main(String[] args) {
        // Create a graph with 5 vertices
        Graph1 graph = new Graph1(5);

        // Add edges
        graph.addEdge(0, 1);
        graph.addEdge(0, 4);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);

        // Print the graph
        graph.printGraph();
    }
}