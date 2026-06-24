//
// Created by iyedbenaicha on 6/24/26.
// Problem Link: https://codeforces.com/problemset/problem/522/A
//

#ifndef CODING_BETOUNSI_REPOSTS_H
#define CODING_BETOUNSI_REPOSTS_H

#endif //CODING_BETOUNSI_REPOSTS_H
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef vector<string> vs;
typedef unordered_map<string, vs> msvs;
typedef unordered_map<string, bool> msb;

class Solution {
private:
    int m;
    string reference = "polycarp" ;
    msvs graph;
    msb visited;

    string lower(string s) {
        transform(
            s.begin(), s.end(), s.begin(), [] (unsigned char c) {
            return tolower(c);
        }) ;
        return s;
    }

    int dfs(string source) {
        int ans = 1;
        visited[source] = true;
        for (auto child: graph[source]) {
            if (!visited[child]) {
                ans = max(ans, dfs(child)+1);
            }
        }
        return ans;
    }

public:
    void solve() {
        cin>>m;
        cin.ignore(); // remove newline after n
        string repost, sep=" reposted ";
        while (m--) {
            getline(cin, repost);
            repost = lower(repost);
            size_t sep_position = repost.find(sep);
            string u = repost.substr(0, sep_position);
            string v = repost.substr(sep_position+ sep.length());
            graph[v].push_back(u);
            visited[v] = false;
            visited[u] = false;
        }
        cout << dfs(reference) << endl;
    }
};
