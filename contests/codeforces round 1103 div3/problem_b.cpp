//
// Created by iyedbenaicha on 6/13/26.
// problem link: https://codeforces.com/contest/2236/problem/B
//

#include "problem_b.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
map<ll, map<ll, ll>> dp;

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

int main_function() { // Before running, you must convert this function name from "main_function()" to "main()"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
    int t=1;
    cin>>t;
    while (t--) {
        test_case();
    }
    return 0;
}
