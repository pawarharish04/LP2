#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;

    void DFSRecursive(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex])
        {
            if (!visited[neighbor])
            {
                DFSRecursive(neighbor, visited);
            }
        }
    }

public:

    Graph(int v)
    {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(vertices, false);

        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    void DFS(int startVertex)
    {
        vector<bool> visited(vertices, false);

        cout << "DFS Traversal: ";

        DFSRecursive(startVertex, visited);

        cout << endl;
    }
};

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    int startVertex;

    cout << "Enter starting vertex: ";
    cin >> startVertex;

    g.BFS(startVertex);

    g.DFS(startVertex);

    return 0;
}