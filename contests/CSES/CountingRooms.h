//
// Created by iyedbenaicha on 7/20/26.
// Problem link: https://cses.fi/problemset/task/1192
//

#ifndef CODING_BETOUNSI_COUNTINGROOMS_H
#define CODING_BETOUNSI_COUNTINGROOMS_H

#endif //CODING_BETOUNSI_COUNTINGROOMS_H

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1007;
const int INF = 1e9;

class Solution {
private:
    int ans = 0, n, m;
    vector<bitset<N>> visited;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string grid[N];

    bool check_inside(int &x, int &y, int k) {
        x += dx[k];
        y += dy[k];
        return 0 <= x && x < n && 0 <= y && y < m;
    }

    void dfs(int i, int j) {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x=i, y=j;
            if (check_inside(x,y,k) && !visited[x][y] && grid[x][y] == '.') dfs(x, y);
        }
    }


public:

    void solve() {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        visited.assign(n, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '.' && !visited[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;

    }
};

