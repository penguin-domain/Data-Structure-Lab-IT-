#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); 

// Adjacency List Representation
class Graph {
public:
    int V; // Number of vertices
    vector<pair<int, int>> *adjList; 

    Graph(int V) {
        this->V = V;
        adjList = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        // For undirected graph:
        // adjList[v].push_back({u, w}); 
    }

    void dijkstra(int src) {
        vector<int> dist(V, INF); 
        dist[src] = 0; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, src}); 

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the distances from the source to all other vertices
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << " \t\t " << dist[i] << endl;
        }
    }
};

// Adjacency Matrix Representation
class GraphMatrix {
public:
    int V;
    int** adjMatrix;

    GraphMatrix(int V) {
        this->V = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; ++i) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = INF; 
            }
        }
    }

    void addEdge(int u, int v, int w) {
        adjMatrix[u][v] = w;
        // For undirected graph:
        // adjMatrix[v][u] = w;
    }

    void dijkstra(int src) {
        vector<int> dist(V, INF); 
        dist[src] = 0;
        vector<bool> visited(V, false);

        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, visited); 
            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        // Print the distances from the source to all other vertices
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << " \t\t " << dist[i] << endl;
        }
    }

    int minDistance(vector<int>& dist, vector<bool>& visited) {
        int min = INF, min_index;

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        return min_index;
    }
};

int main() {
    // Example usage: Adjacency List
    int V = 5; 
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 4, 9);

    cout << "Dijkstra (Adjacency List):" << endl;
    g.dijkstra(0); 

    // Example usage: Adjacency Matrix
    GraphMatrix gm(V);

    gm.addEdge(0, 1, 10);
    gm.addEdge(0, 4, 5);
    gm.addEdge(1, 2, 3);
    gm.addEdge(2, 3, 1);
    gm.addEdge(1, 4, 2);
    gm.addEdge(3, 4, 9);

    cout << "\nDijkstra (Adjacency Matrix):" << endl;
    gm.dijkstra(0);

    return 0;
}
