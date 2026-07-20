//
// Created by iyedbenaicha on 6/9/26.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 52;
const int INF = 1e9;

struct Edge {
    int u, v;
    ll cost;
    Edge(): u(0), v(1), cost(INF) {}
    Edge(int u, int v, ll cost) : u(u), v(v), cost(cost) {}
};

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<Edge> ve;
typedef vector<ve> vve;
typedef vector<ll> vl;

class Solution {
private:
    int n;
    vve graph;
    vb visited;
    bool connected = false;

    vl cost_and_score(int u, ll k) {
        if (u == n-1) {
            connected = true;
            return {0, INF, 0};
        }
        visited[u] = true;
        ll total_cost = INF, min_cost = INF, max_score = 0;
        for (Edge e : graph[u]) {
            if (!visited[e.v]) {
                vl temp = cost_and_score(e.v, k);
                if (temp[0] + e.cost<=k ) {
                    total_cost = temp[0] + e.cost;
                    min_cost = min(temp[1], e.cost);
                    max_score = max(max_score, min_cost);
                }
            }
        }
        return {total_cost, min_cost, max_score};
    }

public:
    int findMaxPathScore(vvi& edges, vb& online, ll k) {
        // if node x is offline don't add it to the adj list
        // if an edge with a cost > k don't consider it in the graph
        // in the same function, return the recovery cost and the score of the path from u to n-1
        n = online.size();
        visited.assign(n, false);
        graph.resize(n);
        for (vi edge : edges) {
            int u=edge[0], v=edge[1], cost=edge[2];
            if (online[u] && online[v] && cost<=k) {
                graph[u].push_back(Edge(u, v, cost));
            }
        }
        int ans = cost_and_score(0, k)[2];
        if (!connected) return -1;
        return ans;


    }
    void solve() {
        int u, v, e, c;
        ll k;
        cin>>v>>e>>k;
        vvi edges;
        vb online;
        while (v--) {
            cin>>u;
            online.push_back(u>0);
        }
        while (e--) {
            cin>>u>>v>>c;
            edges.push_back({u, v, c});
        }
        cout<<findMaxPathScore(edges, online, k)<<endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);

    int t=1;
    // cin>>t;
    while (t--) {
        Solution s;
        s.solve();
    }
    return 0;
}
