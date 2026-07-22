//
// Created by iyedbenaicha on 7/22/26.
// problem link: https://cses.fi/problemset/result/18044245/
//

#ifndef CODING_BETOUNSI_ROUNDTRIP_H
#define CODING_BETOUNSI_ROUNDTRIP_H

#endif //CODING_BETOUNSI_ROUNDTRIP_H

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100007;
const int INF = 1e9;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
private:
    int n, m;
    vvi graph;
    bitset<N> visited;
    vi parent;

    int detect_cycle(int u, int s=-1) {
        visited[u] = true;
        for (int v: graph[u]) {
            if (visited[v] && v!=s) {
                parent[v] = u;
                return v;
            }
            if (!visited[v]) {
                parent[v] = u;
                if (int node = detect_cycle(v, u)) return node;
            }
        }
        return 0;
    }

public:

    void solve() {
        cin>>n>>m;
        graph.resize(n+1);
        parent.assign(n+1, 0);
        int u, v;
        while (m--) {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int source = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] ) {
                source = detect_cycle(i);
                if (source) break;
            }
        }
        if (source == 0) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        vi ans = {source};
        while (parent[source] != ans[0]) {
            source = parent[source];
            ans.push_back(source);
        }
        ans.push_back(ans[0]);
        cout<<ans.size()<<endl;
        for (int i: ans) cout<<i<<" ";
    }
};

