//
// Created by iyedbenaicha on 7/3/26.
// Problem Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/?envType=daily-question&envId=2026-07-02
//

#ifndef CODING_BETOUNSI_FIND_A_SAFE_WALK_THROUGH_A_GRID_H
#define CODING_BETOUNSI_FIND_A_SAFE_WALK_THROUGH_A_GRID_H

#endif //CODING_BETOUNSI_FIND_A_SAFE_WALK_THROUGH_A_GRID_H


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> v3d;

class Solution1 {
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
};


class Solution2 {
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    v3d dp;

    bool check_inside(int &x, int &y, int p){
        x += dx[p];
        y += dy[p];
        return ( 0<=x && x<n && 0<=y && y<m );
    }
    bool walk_is_safe_from(int ui, int uj, int h, vvi &grid){
        h -= grid[ui][uj];
        if (h < 1) return dp[ui][uj][h] = 0;
        if (ui == n-1 && uj == m-1) return dp[ui][uj][h] = 1;
        if (dp[ui][uj][h] >= 0) return dp[ui][uj][h];
        dp[ui][uj][h] = -1;
        int ans = 0;
        for(int k=0; k<4; k++){
            int vi=ui, vj=uj;
            if (!check_inside(vi, vj, k) ) continue;
            if (dp[vi][vj][h] == -1) continue;
            if (walk_is_safe_from(vi, vj, h, grid)) {
                ans = 1;
                break;
            }
        }
        return dp[ui][uj][h] = ans;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vvi(m, vi(n+m+7, -2)));
        return walk_is_safe_from(0, 0, health, grid);
    }
};