#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int V;                    // Number of vertices
    vector<vector<int>> adjm; // Adjacency Matrix

    // Recursive helper function for DFS
    void topologicalSortUtil(int u, vector<bool> &visited, stack<int> &T)
    {
        // Mark the current node as visited
        visited[u] = true;

        // Iterate through all vertices to find neighbors of u
        // In matrix: Check row 'u'
        for (int v = 0; v < V; v++)
        {
            // If there is an edge u -> v AND v is not visited
            if (adjm[u][v] == 1 && !visited[v])
            {
                topologicalSortUtil(v, visited, T);
            }
        }

        // Push current vertex to stack (Finishing Time logic)
        // This happens only when all children are visited
        T.push(u);
    }

public:
    Graph(int vertices)
    {
        this->V = vertices;
        // Initialize matrix with 0s
        this->adjm.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v)
    {
        // Add directed edge u -> v
        adjm[u][v] = 1;
    }

    void dfsTopologicalSort()
    {
        stack<int> T; // This stack acts as our "Insert at Beginning" list
        vector<bool> visited(V, false);

        // Call the recursive helper function to store Topological Sort
        // starting from all vertices one by one (handles disconnected graphs)
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSortUtil(i, visited, T);
            }
        }

        // Print contents of stack
        cout << "Topological Sort (DFS Matrix): ";
        while (!T.empty())
        {
            cout << T.top() << " ";
            T.pop();
        }
        cout << endl;
    }
};

int main()
{
    // Example Graph with 6 vertices (0-5)
    // Same example as Kahn's: 0->1, 1->2, 2->3, 0->3, 3->4, 2->4

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);

    // Node 5 is isolated, so it will appear first or last depending on iteration order
    // (In this implementation, loop visits 0..5, so 5 is visited last, pushed first)

    g.dfsTopologicalSort();

    return 0;
}