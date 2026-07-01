//
// Created by iyedbenaicha on 7/1/26.
// Problem link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2026-07-01
//

#ifndef CODING_BETOUNSI_2812_FIND_THE_SAFETEST_PATH_IN_A_GRID_H
#define CODING_BETOUNSI_2812_FIND_THE_SAFETEST_PATH_IN_A_GRID_H

#endif //CODING_BETOUNSI_2812_FIND_THE_SAFETEST_PATH_IN_A_GRID_H

#include <bits/stdc++.h>
using namespace std;
const int N = 400;
typedef vector<int> vi;
typedef vector<vi> vvi;


class Solution {
private:
    int n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vvi dist, ans;
    const int INF = 807;
    priority_queue<vi> pq;

    bool inside_grid(int &x, int &y, int p){
        x += dx[p];
        y += dy[p];
        return 0<=x && x<n && 0<= y && y < n;
    }

    void init_grid(vvi &grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    pq.push({0, i, j});
                }
            }
        }
    }
    void fill_dist() {
        while (!pq.empty()) {
            vi u = pq.top();
            pq.pop();
            int dis = -u[0], i=u[1], j=u[2];
            if (dis>dist[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int x=i, y=j;
                if (inside_grid(x, y, k) && dis+1<dist[x][y]) {
                    dist[x][y] = dis+1;
                    pq.push({-dist[x][y], x, y});
                }
            }
        }
    }
    int safeness_factor() {
        pq.push({dist[n-1][n-1], n-1, n-1});
        ans[n-1][n-1] = dist[n-1][n-1];
        while (!pq.empty()) {
            vi u = pq.top();
            pq.pop();
            int factor_ij = u[0], i=u[1], j=u[2];
            if (factor_ij < ans[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int x=i, y=j;
                if (!inside_grid(x, y, k)) continue;
                int factor_xy = min(factor_ij, dist[x][y]);
                if (factor_xy > ans[x][y]) {
                    ans[x][y] = factor_xy;
                    pq.push({factor_xy, x, y});
                }
            }
        }
        return ans[0][0];
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        dist.assign(n, vi(n, INF));
        ans.assign(n, vi(n, -INF));
        init_grid(grid);
        fill_dist();
        return safeness_factor();
    }
    void solve() {
        int k;
        cin >> k;
        vvi grid(k, vi(k));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> grid[i][j];
            }
        }
        cout<<maximumSafenessFactor(grid)<<endl;
    }
};
