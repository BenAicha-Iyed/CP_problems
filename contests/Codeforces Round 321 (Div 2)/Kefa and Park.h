//
// Created by iyedbenaicha on 6/23/26.
// problem link: https://codeforces.com/contest/580/problem/C
//

#ifndef CODING_BETOUNSI_KEFA_AND_PARK_H
#define CODING_BETOUNSI_KEFA_AND_PARK_H

#endif //CODING_BETOUNSI_KEFA_AND_PARK_H

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

class Solution {
private:
    int n = 0, m = 0;
    vvi tree;
    vi consecutive_cats, cats, parent;
    vb visited;

    void dfs(int source) {
        visited[source] = true;
        for (auto child: tree[source]) {
            if (!visited[child]) {
                parent[child] = source;
                if (consecutive_cats[source] > m ) consecutive_cats[child] = consecutive_cats[source];
                else if (cats[child] == 1) {
                    consecutive_cats[child] = consecutive_cats[source]*cats[source] + 1;
                }
                dfs(child);
            }
        }
    }
    bool is_leaf(int vertex) {
        return (tree[vertex].size() == 1 && tree[vertex][0] == parent[vertex]);
    }
public:
    void solve() {
        cin>>n>>m;
        int u, v, ans=0;
        tree.assign(n+1, vi());
        cats.assign(n+1, 0);
        consecutive_cats.assign(n+1, 0);
        visited.assign(n+1, false);
        parent.assign(n+1, 0);
        for (int i=1; i<=n; i++) {
            cin>>cats[i];
        }
        for (int i=0; i<n-1; i++) {
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        consecutive_cats[1] = cats[1];
        dfs(1);
        for (int i=1; i<=n; ++i) {
            ans += (consecutive_cats[i] <= m) * (is_leaf(i));
        }
        cout << ans << endl;
    }
};