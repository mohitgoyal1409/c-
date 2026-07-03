#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs()
    {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(0);
        visited[0] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : l[u])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.bfs();
}
