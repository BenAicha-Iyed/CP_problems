//
// Created by iyedbenaicha on 6/23/26.
// Problem link: https://codeforces.com/problemset/problem/687/A
//

#ifndef CODING_BETOUNSI_NP_HARD_PROBLEM_H
#define CODING_BETOUNSI_NP_HARD_PROBLEM_H

#endif //CODING_BETOUNSI_NP_HARD_PROBLEM_H

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

class Solution {
private:
    int n, m;
    vvi graph, groups;
    vi color;

    bool bfs(int source) {
        queue<int> q;
        q.push(source);
        color[source] = 1;
        int u;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            groups[color[u]-1].push_back(u);
            for (int v : graph[u]) {
                if (color[v] == 0) {
                    color[v] =  3 - color[u];
                    q.push(v);
                }else if (color[u] == color[v]) {
                    ////// cannot create a bipartite graph
                    return false;
                }
            }
        }
        return true;
    }

    void split_graph() {
        for (int i=1;i<=n;i++) {
            if (color[i] == 0 && !bfs(i)) {
                cout << -1 << endl;
                return;
            }
        }

        for (vi g : groups) {
            cout << g.size() << endl;
            for (int nd: g) cout << nd << " ";
            cout << endl;
        }
    }

public:
    void solve() {
        int u, v;
        cin>>n>>m;
        graph.assign(n+1, vi());
        color.assign(n+1, 0);
        groups.assign(2, vi());
        while (m--) {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        split_graph();
    }
};

