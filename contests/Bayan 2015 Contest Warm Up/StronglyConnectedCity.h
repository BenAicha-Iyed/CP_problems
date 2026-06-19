//
// Created by iyedbenaicha on 6/14/26.
// Problem link: https://codeforces.com/contest/475/problem/B
//

#ifndef CODING_BETOUNSI_STRONGLYCONNECTEDCITY_H
#define CODING_BETOUNSI_STRONGLYCONNECTEDCITY_H
#include <bits/stdc++.h>
using namespace std;


class StronglyConnectedCity {
private:
    int n = 0, m = 0;
    vector <vector<bool>> visited;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string rows, cols;

    vector<int> neighbours(int i, int j) {
        vector<int> res;
        if (cols[j] == 'v') res.push_back(0);
        else res.push_back(2);
        if (rows[i] == '>') res.push_back(1);
        else res.push_back(3);
        return res;
    }

    bool inside_maze(int &x, int &y, int pos) const {
        x += dx[pos];
        y += dy[pos];
        return x >= 0 && x < n && y >= 0 && y < m ;
    }

    void dfs(int i=0, int j=0) {
        visited[i][j] = true;
        int x, y;
        for (int p : neighbours(i, j)) {
            x=i, y=j;
            if (inside_maze(x, y, p) && !visited[x][y]) dfs(x, y);
        }
    }

    bool check_connectivity() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!visited[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solve() {
        cin >> n >> m >> rows >> cols;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                visited.assign(n, vector<bool>(m, false));
                dfs(i, j);
                if (!check_connectivity()) {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        cout<<"YES"<<endl;
    }
};


#endif //CODING_BETOUNSI_STRONGLYCONNECTEDCITY_H
