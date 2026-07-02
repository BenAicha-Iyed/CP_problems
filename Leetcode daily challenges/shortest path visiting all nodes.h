//
// Created by iyedbenaicha on 7/2/26.
// Problem link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
//

#ifndef CODING_BETOUNSI_SHORTEST_PATH_VISITING_ALL_NODES_H
#define CODING_BETOUNSI_SHORTEST_PATH_VISITING_ALL_NODES_H

#endif //CODING_BETOUNSI_SHORTEST_PATH_VISITING_ALL_NODES_H


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 400;
typedef vector<int> vi;
typedef vector<vi> vvi;


class Solution {
private:
    int n, visited=0;
    const int INF = 20;
    vvi dist, dp;

    bool check_element(int i, int mask) {
        return (mask>>i)&1 ;
    }

    int set_element(int i, int mask) {
        return mask | (1<<i);
    }

    void init_dp() {
        for (int i=0; i<n; i++) {
            dp.assign(n, vi(1<<n, -1));
        }
        visited = 0;
    }

    void build_dist(int s, vvi &graph) {
        queue<int> q;
        q.push(s);
        dist[s].assign(n, INF);
        dist[s][s] = 0;
        visited = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (check_element(v, visited)) continue;
                dist[s][v] = min(dist[s][v], dist[s][u] + 1);
                visited = set_element(v, visited);
                q.push(v);
            }
        }
    }

    int shortest_path_from(int u, int mask, vvi &graph) {
        if (dp[u][mask] != -1) return dp[u][mask];
        if (mask == (1<<n) - 1 ) return dp[u][mask]=0;
        int ans = INF;
        for (int v=0; v<n; v++) {
            if (check_element(v, mask)) continue;
            ans = min(ans, dist[u][v] + shortest_path_from(v, set_element(v, mask) , graph   )     );
        }
        return dp[u][mask] = ans;
    }

public:

    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        dist.resize(n);
        for (int i = 0; i < n; i++) build_dist(i, graph);
        init_dp();
        int ans = INF;
        for (int s = 0; s < n; s++) {
            ans = min(ans, shortest_path_from(s, 1<<s, graph));
        }
        return ans;
    }

    void solve() {
        int m, n_ch, v;
        cin >> m;
        vvi graph(m);
        for (int u=0; u<m; u++) {
            cin >> n_ch;
            while (n_ch--) {
                cin >> v;
                graph[u].push_back(v);
            }
        }
        cout << shortestPathLength(graph)<<endl;
    }
};
