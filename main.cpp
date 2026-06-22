//
// Created by iyedbenaicha on 6/9/26.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
private:
    string text;
public:
    void solve() {
        cin>>text;
        unordered_map<char, int> min_occ = {
            {'a', 1},
            {'b', 1},
            {'n', 1},
            {'l', 2},
            {'o', 2}
        };
        map<char, int> total_occ;
        for (char c : text) {
            if (min_occ.find(c) != min_occ.end()) total_occ[c]++;
        }
        int ans = text.size();
        for (auto it: min_occ) {
            ans = min(ans, total_occ[it.first]/it.second);
        }
        cout<<ans<<endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
    Solution s;
    int t=1;
    cin>>t;
    while (t--) {
        s.solve();
    }
    return 0;
}
