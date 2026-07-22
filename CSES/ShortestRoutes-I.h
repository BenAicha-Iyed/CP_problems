//
// Created by iyedbenaicha on 7/22/26.
// Problem link: https://cses.fi/problemset/task/1671
//

#ifndef CODING_BETOUNSI_SHORTESTROUTES_I_H
#define CODING_BETOUNSI_SHORTESTROUTES_I_H

#endif //CODING_BETOUNSI_SHORTESTROUTES_I_H

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100007;
const ll INF = LONG_LONG_MAX;
typedef vector<ll> vi;
typedef pair<ll, int> lli;
typedef vector<lli> vli;
typedef vector<vli> vg;

#define node second
#define cost first

class Solution {
private:
    int n, m;
    vg graph;
    vi dist;
    void dijkistra(int s) {
        dist[s] = 0;
        priority_queue<lli> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            lli u = pq.top();
            pq.pop();
            if (dist[u.node] < -u.cost) continue;
            for (lli v : graph[u.node]) {
                if (dist[v.node] > dist[u.node] + v.cost) {
                    dist[v.node] = dist[u.node] + v.cost;
                    pq.emplace(-dist[v.node], v.node);
                }
            }
        }
    }

public:

    void solve() {
        cin>>n>>m;
        graph.resize(n+1);
        dist.assign(n+1, INF);
        int a, b;
        ll c;
        while (m--) {
            cin>>a>>b>>c;
            graph[a].emplace_back(c, b);
        }
        dijkistra(1);
        for (int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
    }
};
