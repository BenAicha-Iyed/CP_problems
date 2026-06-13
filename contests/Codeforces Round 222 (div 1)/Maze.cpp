//
// Created by iyedbenaicha on 6/13/26.
// Problem link: https://codeforces.com/contest/377/problem/A
//

#include "Maze.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
private:
    int n = 0, m = 0, k = 0;
    vector<vector<bool>> visited;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<string> maze;

    bool inside_maze(int &x, int &y, int pos) const {
        x += dx[pos];
        y += dy[pos];
        return x >= 0 && x < n && y >= 0 && y < m ;
    }
    void display_maze() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
    }
    int dfs(int i, int j, int empty_cells) {
        visited[i][j] = true;
        int x, y;
        for (int p = 0; p < 4; p++) {
            x=i, y=j;
            if (inside_maze(x, y, p) && !visited[x][y] && maze[x][y] == '.') {
                empty_cells = max(empty_cells-1, 0);
                if (empty_cells == 0) {
                    maze[x][y] = 'X';
                }
                empty_cells = dfs(x, y, empty_cells);
            }
        }
        return empty_cells;
    }
public:
    void main() {
        maze.clear();
        visited.clear();
        cin >> n >> m >> k;
        maze.resize(n);
        visited.assign(n, vector<bool>(m, false));
        int nb_empty=0, sx=0, sy=0;
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == '.') {
                    nb_empty++;
                    sx = i; sy = j;
                }
            }
        }
        dfs(sx, sy, nb_empty-k);
        display_maze();
    }
};
