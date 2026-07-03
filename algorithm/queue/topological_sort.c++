#include<iostream>
#include<queue>
using namespace std;
#include<vector>
#include<list>

class Graph {
    int V;
    list<int> *l;

    public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x,int y) {
        l[x].push_back(y);
    }

    void toposort() {
        vector<int>res;

        vector<int>indegree(V,0);
        for(int i = 0;i<V;i++) {
            for(int v:l[i]) {
                indegree[v]++;
            }
        } 

        queue<int>q;
        for(int i = 0;i<V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int v:l[curr]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        for(int i = 0;i<res.size();i++) {
            cout<<res[i]<<" ";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.toposort();
}





