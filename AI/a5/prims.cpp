#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:

    // Constructor
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    // Add edge
    void addEdge(int u, int v, int wt)
    {
        adj[u][v] = wt;
        adj[v][u] = wt;
    }

    // Prim's Algorithm
    int prims()
    {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<bool> visited(V, false);

        int res = 0;

        // {weight, vertex}
        pq.push({0, 0});

        cout << "MST Traversal: ";

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int u = p.second;

            // Skip if already visited
            if (visited[u])
                continue;

            visited[u] = true;

            cout << u << " ";

            res += wt;

            // Explore neighbors
            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] != 0 && !visited[v])
                {
                    pq.push({adj[u][v], v});
                }
            }
        }

        cout << "\nMinimum Cost of MST = " << res << endl;

        return res;
    }
};

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        g.addEdge(u, v, wt);
    }

    cout << endl;

    g.prims();

    return 0;
}