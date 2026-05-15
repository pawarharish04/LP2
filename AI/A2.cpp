#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node
{
public:
    int x, y;
    int g, h, f;

    Node* parent;

    Node(int x, int y, Node* parent = nullptr)
    {
        this->x = x;
        this->y = y;
        this->parent = parent;

        g = h = f = 0;
    }
};

// Comparator for Priority Queue
class Compare
{
public:
    bool operator()(Node* a, Node* b)
    {
        return a->f > b->f;
    }
};

// A* Algorithm Class
class AStar
{
private:
    vector<vector<int>> maze;

    int rows, cols;

public:
    AStar(vector<vector<int>> grid)
    {
        maze = grid;

        rows = maze.size();

        cols = maze[0].size();
    }

    // Check valid position
    bool isValid(int x, int y)
    {
        return (x >= 0 && x < rows &&
                y >= 0 && y < cols);
    }

    // Check obstacle
    bool isUnBlocked(int x, int y)
    {
        return maze[x][y] == 0;
    }

    // Heuristic Function
    int calculateH(int x, int y, int endX, int endY)
    {
        return abs(x - endX) + abs(y - endY);
    }

    // Print Final Path
    void printPath(Node* node)
    {
        vector<pair<int, int>> path;

        while (node != nullptr)
        {
            path.push_back({node->x, node->y});

            node = node->parent;
        }

        reverse(path.begin(), path.end());

        cout << "\nShortest Path:\n";

        for (auto p : path)
        {
            cout << "(" << p.first
                 << "," << p.second << ") ";
        }

        cout << endl;

        // Display maze with path
        for (auto p : path)
        {
            maze[p.first][p.second] = 2;
        }

        cout << "\nMaze Path:\n";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (maze[i][j] == 2)
                    cout << "* ";
                else
                    cout << maze[i][j] << " ";
            }

            cout << endl;
        }
    }

    // A* Search Function
    void findPath(pair<int, int> start,
                  pair<int, int> end)
    {
        priority_queue<Node*,
                       vector<Node*>,
                       Compare> openList;

        vector<vector<bool>> visited(rows,
                                     vector<bool>(cols, false));

        Node* startNode =
            new Node(start.first, start.second);

        openList.push(startNode);

        // Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};

        int dy[] = {0, 0, -1, 1};

        while (!openList.empty())
        {
            Node* current = openList.top();

            openList.pop();

            int x = current->x;

            int y = current->y;

            // Destination Found
            if (x == end.first &&
                y == end.second)
            {
                cout << "Destination Found!\n";

                printPath(current);

                return;
            }

            visited[x][y] = true;

            // Explore neighbors
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];

                int newY = y + dy[i];

                if (isValid(newX, newY) &&
                    isUnBlocked(newX, newY) &&
                    !visited[newX][newY])
                {
                    Node* neighbor =
                        new Node(newX, newY, current);

                    neighbor->g = current->g + 1;

                    neighbor->h =
                        calculateH(newX, newY,
                                   end.first, end.second);

                    neighbor->f =
                        neighbor->g + neighbor->h;

                    openList.push(neighbor);
                }
            }
        }

        cout << "No Path Found!\n";
    }
};

// Main Function
int main()
{
    vector<vector<int>> maze =
    {
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    pair<int, int> start = {0, 0};

    pair<int, int> end = {7, 6};

    AStar pathfinder(maze);

    pathfinder.findPath(start, end);

    return 0;
}