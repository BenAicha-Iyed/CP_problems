//
// Created by iyedbenaicha on 6/9/26.
// Problem link: https://codeforces.com/contest/2233/problem/A
// Solution link: https://codeforces.com/contest/2233/submission/377950159
//

#include "Problem-A_AI-Project-Development.h"
#include <bits/stdc++.h>
using namespace std;

int upper_int(int a, int b) {
    if (a <= b) return 1;
    return a/b + (a%b != 0);
}

void test_case() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout <<min(upper_int(n, x+y), z + upper_int(n - x*z, x + 10*y) ) << endl;
}

int main() {
    int t=1;
    cin>>t;
    while (t--) {
        test_case();
    }
    return 0;
}

