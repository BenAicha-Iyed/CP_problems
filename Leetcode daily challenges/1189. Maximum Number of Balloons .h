//
// Created by iyedbenaicha on 6/22/26.
// problem link: https://leetcode.com/problems/maximum-number-of-balloons/
//

#ifndef CODING_BETOUNSI_1189_MAXIMUM_NUMBER_OF_BALLOONS_H
#define CODING_BETOUNSI_1189_MAXIMUM_NUMBER_OF_BALLOONS_H

#endif //CODING_BETOUNSI_1189_MAXIMUM_NUMBER_OF_BALLOONS_H

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<char, int> min_occ = {
        {'a', 1},
        {'b', 1},
        {'n', 1},
        {'l', 2},
        {'o', 2}
    };
    unordered_map<char, int> total_occ;
public:
    int maxNumberOfBalloons(string text) {
        for (char c : text) {
            if (min_occ.find(c) != min_occ.end()) total_occ[c]++;
        }
        int ans = text.size();
        for (auto it: min_occ) {
            ans = min(ans, total_occ[it.first]/it.second);
        }
        return ans;
    }
};
