#include<iostream>
#include<queue>
using namespace std;
#include<vector>

int orangeRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(grid[i][j] == 2) {
                q.push({{i,j},0});
            }
        }
    }

    while(q.size() > 0) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int t = q.front().second;
        q.pop();

        ans = max(ans,t);
        if(i-1 >=0 && !vis[i-1][j] && grid[i-1][j] == 1) {
            vis[i-1][j] = true;
            q.push({{i-1,j},t+1});
        }
        if(j+1 <m && !vis[i][j+1] && grid[i][j+1] == 1) {
            vis[i][j+1] = true;
            q.push({{i,j+1},t+1});
        }
        if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1) {
            vis[i+1][j] = true;
            q.push({{i+1,j},t+1});
        }
        if(j-1 >=0 && !vis[i][j-1] && grid[i][j-1] == 1) {
            vis[i][j-1] = true;
            q.push({{i,j-1},t+1});
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                return -1;
            }
        }
    }
    return ans;
}


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    for(int i = 0;i<n;i++) {
        vector<int> temp;
        for(int j = 0;j<m;j++) {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }

    int result = orangeRotting(grid);
    cout<<result<<endl;
}