//
// Created by iyedbenaicha on 6/22/26.
// Problem link: https://leetcode.com/problems/maximum-ice-cream-bars/description/
//

#ifndef CODING_BETOUNSI_1833_MAXIMUM_ICE_CREAM_BARS_H
#define CODING_BETOUNSI_1833_MAXIMUM_ICE_CREAM_BARS_H

#endif //CODING_BETOUNSI_1833_MAXIMUM_ICE_CREAM_BARS_H

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int> occ;
        for(auto cost: costs){
            occ[cost]++;
        }
        int ans=0, temp;
        for(auto it:occ){
            if (coins <= 0) break;
            temp = min(it.second, coins/it.first);
            ans += temp;
            coins -= temp*it.first;

        }
        return ans;
    }
};