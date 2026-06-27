//
// Created by iyedbenaicha on 6/27/26.
//

#ifndef CODING_BETOUNSI_B_FOX_AND_TWO_DOTS_H
#define CODING_BETOUNSI_B_FOX_AND_TWO_DOTS_H

#endif //CODING_BETOUNSI_B_FOX_AND_TWO_DOTS_H
using namespace std;
using ll = long long;
const int N = 53;

class Solution {
private:
    int n, m;
    vector<string> grid;
    vector<bitset<N> > vis;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool check_inside(int &x, int &y, int pos) {
        x += dx[pos];
        y += dy[pos];
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool check_cycle(int si, int sj, int pi=-1, int pj=-1) {
        vis[si][sj] = true;
        for (int k=0; k<4; k++) {
            int x=si, y=sj;
            if (check_inside(x, y, k) && grid[si][sj] == grid[x][y]) {
                if (  vis[x][y] && (pi != x || pj != y)   ) return true;
                if (!vis[x][y] && check_cycle(x, y, si, sj)) return true;
            }
        }
        return false;
    }

public:
    void solve() {
        cin >> n >> m;
        grid.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && check_cycle(i, j)) {
                    cout<<"Yes"<<endl;
                    return ;
                }
            }
        }
        cout<<"No"<<endl;
    }
};
