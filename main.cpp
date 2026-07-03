//
// Created by iyedbenaicha on 6/9/26.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 52;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    const int INF = 1e9;
    vvi dp;

    bool check_inside(int &u, int &v, int p){
        u += dx[p];
        v += dy[p];
        return ( 0<=u && u<n && 0<=v && v<m );
    }

    int min_consumption(vvi grid){
        dp[n-1][m-1] = grid[n-1][m-1];
        queue<vi> q;
        q.push({n-1, m-1});
        while(!q.empty()) {
            vi u = q.front();
            int i= u[0], j= u[1];
            q.pop();
            for (int k=0; k<4; k++) {
                int x=i, y=j;
                if (check_inside(x,y,k) && dp[x][y] > dp[i][j] + grid[x][y]) {
                    q.push({x, y});
                    dp[x][y] = dp[i][j] + grid[x][y];
                }
            }
        }
        int ans = dp[0][0];
        dp.clear();
        return ans;
    }


public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vi(m, INF));
        return health > min_consumption( grid);
    }
    void solve() {
        int r, c, h;
        cin>>r>>c>>h;
        vvi grid;
        grid.assign(r, vi(c));
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin>>grid[i][j];
            }
        }
        cout<<findSafeWalk(grid, h)<<endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);

    int t=1;
    // cin>>t;
    while (t--) {
        Solution s;
        s.solve();
    }
    return 0;
}
