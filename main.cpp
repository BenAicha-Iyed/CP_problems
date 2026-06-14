//
// Created by iyedbenaicha on 6/9/26.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
    private:
        int n = 0, m = 0;
        vector<vector<bool>> visited;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        string rows, cols;

        bool inside_maze(int &x, int &y, int pos) const {
            x += dx[pos];
            y += dy[pos];
            return x >= 0 && x < n && y >= 0 && y < m ;
        }

        void dfs(int i=0, int j=0) {
            visited[i][j] = true;
            int x, y;

        }
    public:
        void solve() {
            visited.clear();
            cin >> n >> m;
            visited.assign(n, vector<bool>(m, false));
            cin >> rows >> cols;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
    Solution s;
    int t=1;
    // cin>>t;
    while (t--) {
        s.solve();
    }
    return 0;
}
