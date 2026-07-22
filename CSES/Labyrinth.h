//
// Created by iyedbenaicha on 7/22/26.
// problem link: https://cses.fi/problemset/result/18042165/
//

#ifndef CODING_BETOUNSI_LABYRINTH_H
#define CODING_BETOUNSI_LABYRINTH_H

#endif //CODING_BETOUNSI_LABYRINTH_H

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1007;
const int INF = 1e9;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define row first
#define col second

class Solution {
private:

    int n, m;
    vector<bitset<N>> visited;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string grid[N], moves="DRUL";
    vvi dep;

    bool check_inside(int &x, int &y, int k) {
        x += dx[k];
        y += dy[k];
        return 0 <= x && x < n && 0 <= y && y < m;
    }

    void bfs(int xA, int yA) {
        queue<pii> q; // each item contain ({ x, y }, path_from_source_to_current_position)
        q.push({xA, yA});
        visited[xA][yA] = true;
        while (!q.empty()) {
            pii u = q.front();
            q.pop();
            for (int k=0; k<4; k++) {
                int x=u.row, y=u.col;
                if (!check_inside(x, y, k)) continue;
                if (visited[x][y]) continue;
                if (grid[x][y] == 'A' || grid[x][y] == '#') continue;
                visited[x][y] = true;
                dep[x][y] = (k+2)%4;
                if (grid[x][y] == '.') {
                    q.push({x, y});
                }
                if (grid[x][y] == 'B') {
                    return;
                }

            }
        }
    }

    string get_path(int xB, int yB) {
        string ans = "";
        int x= xB, y= yB;
        while (dep[x][y] != -1) {
            ans += moves[(dep[x][y]+2)%4];
            if (!check_inside(x, y, dep[x][y])) break;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:

    void solve() {
        cin >> n >> m;
        int xA=0, yA=0, xB=0, yB=0;
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'A') {
                    xA = i;
                    yA = j;
                    continue;
                }
                if (grid[i][j] == 'B') {
                    xB = i;
                    yB = j;
                }
            }
        }
        visited.assign(n, 0);
        dep.assign(n, vi(m, -1));
        bfs(xA, yA);
        if (dep[xB][yB] == -1) cout<<"NO"<<endl;
        else {
            string ans = get_path(xB, yB);
            cout<<"YES"<<endl<<ans.size()<<endl<<ans<<endl;
        }
    }
};
