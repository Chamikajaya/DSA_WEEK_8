#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the edges of the minimum spanning tree
void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(const vector<vector<int>>& graph, int V, int start) {
    vector<int> parent(V);      // Array to store the constructed MST
    vector<int> key(V, INT_MAX);    // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V, false);   // To represent set of vertices included in MST

    // Start with the given start node
    key[start] = 0;
    parent[start] = -1;     // First node is always the root of MST

    for (int count = 0; count < V - 1; ++count) {
        int u = minKey(key, mstSet, V);  // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true;   // Add the picked vertex to the MST set

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the edges of the minimum spanning tree
    printMST(parent, graph, V);
}

int main() {
    int V = 6; // Number of vertices in the graph

    // Create a graph using adjacency matrix representation
    vector<vector<int>> graph = {
            {0, 3, 0, 0, 0, 1},
            {3, 0, 2, 1, 10, 0},
            {0, 2, 0, 3, 0, 5},
            {0, 1, 3, 0, 5, 0},
            {0, 10, 0, 5, 0, 4},
            {1, 0, 5, 0, 4, 0}

    };

    int startNode1 = 0; // Specify the start node (index)

    // Find the minimum spanning tree using Prim's algorithm
    cout << "When the starting node is 0--> " << endl;
    primMST(graph, V, startNode1);

    return 0;
}
