//
// Created by iyedbenaicha on 6/25/26.
// Problem link: https://leetcode.com/problems/bus-routes/description/?envType=company&envId=uber&favoriteSlug=uber-thirty-days
//

#ifndef CODING_BETOUNSI_BUS_ROUTES_H
#define CODING_BETOUNSI_BUS_ROUTES_H

#endif //CODING_BETOUNSI_BUS_ROUTES_H


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef unordered_set<int> si;
typedef unordered_map<int, si> misi;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
private:
    struct Station {
        int station_id;
        int nb_buses;

        Station(int stop_id, int buses) {
            station_id = stop_id;
            nb_buses = buses;
        }
    };
    si visited;
    misi related_buses;
    queue<Station> to_visit;

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        for (int bus_id=0; bus_id<routes.size(); bus_id++) {
            for (int station_id: routes[bus_id]) {
                related_buses[station_id].insert(bus_id);
            }
        }
        to_visit.push(Station(source, 0));
        visited.insert(source);
        while (!to_visit.empty()) {
            Station current_station = to_visit.front();
            to_visit.pop();
            if (current_station.station_id == target) return current_station.nb_buses;
            for (int bus_id: related_buses[current_station.station_id]) {
                for (int station_id: routes[bus_id]) {
                    auto it = visited.insert(station_id);
                    if (it.second) to_visit.push(Station(station_id, current_station.nb_buses + 1));
                }
                routes[bus_id].clear();
            }
        }
        return -1;
    }

    void solve() {
        int n, source, target, k;
        cin >> n >> source >> target;
        vvi routes(n);
        for (int i=0; i<n; i++) {
            cin>>k;
            routes[i].assign(k, 0);
            for (int j=0; j<k; j++) {
                cin>>routes[i][j];
            }
        }
        cout<<numBusesToDestination(routes,  source,  target)<<endl;
    }
};

