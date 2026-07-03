#include<iostream>
#include<vector>    
using namespace std;
#include<list>

class Graph {
    int V;
    list<int> *l;

    public:
    Graph(int v) {
            this->V = v;
            l = new list<int>[v];
    }

    void addEdge(int x,int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

void dfsHelper(int u, vector<bool> &vis) {
    cout<<u<<" ";
    vis[u] = true;
    for(int v: l[u]) {
        if(!vis[v]) {
            dfsHelper(v,vis);
        }
    }
}


void dfs() {
    int src = 0;
    vector<bool> vis(V,false);

    dfsHelper(src,vis);
    cout<<endl;
}
};

int main() {
      Graph g(7);
        g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(1,3);
        g.addEdge(2,4);
        g.dfs();
}