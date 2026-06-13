//
// Created by iyedbenaicha on 6/9/26.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, map<ll, ll>> dp;
// int n, m, k;
// vector<vector<bool>> visited;
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// vector<string> maze;
//
// bool inside_maze(int &x, int &y, int pos) {
//     x += dx[pos];
//     y += dy[pos];
//     return x >= 0 && x < n && y >= 0 && y < m ;
// }
//
// void dfs(int i, int j, int empty_cells) {
//     visited[i][j] = true;
//     int x=i, y=j;
//     if (empty_cells == 0) maze[i][j] = 'X';
//     else empty_cells--;
//     for (int k = 0; k < 4; k++) {
//         if (inside_maze(x, y, k) && !visited[x][y] && maze[x][y] == '.') {
//             dfs(x, y, empty_cells);
//         }
//     }
// }
//
// void test_case() {
//     maze.clear();
//     visited.clear();
//     cin >> n >> m >> k;
//     maze.resize(n);
//     visited.assign(n, vector<bool>(m, false));
//     int nb_empty=0, sx=0, sy=0;
//     for (int i = 0; i < n; i++) {
//         cin >> maze[i];
//         for (int j = 0; j < m; j++) {
//             if (maze[i][j] == '.') {
//                 nb_empty++;
//                 sx = i; sy = j;
//             }
//         }
//     }
//     dfs(sx, sy, nb_empty-k);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << maze[i][j];
//         }
//         cout << endl;
//     }
// }

ll min_operations(ll a, ll b, ll x) {
    if (a == b) return 0;
    ll maxi = max(a, b), mini = min(a, b);
    ll ans;
    if ( dp.find(maxi) != dp.end() && dp[maxi].find(mini) != dp[maxi].end() ) ans = dp[maxi][mini];
    else if ( dp.find(mini) != dp.end() && dp[mini].find(maxi) != dp[mini].end()  ) ans = dp[mini][maxi];
    else {
        ans = min_operations(maxi/x, mini, x) + 1;
        dp[maxi][mini] = ans;
    }
    return min(ans, maxi-mini);
}

void test_case() {
    ll a, b, x;
    cin >> a >> b >> x;
    dp.clear();
    cout << min_operations(a, b, x) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("errors.txt", "w", stderr);
    int t=1;
    cin>>t;
    while (t--) {
        test_case();
    }
    return 0;
}
