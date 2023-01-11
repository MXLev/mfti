//
// Created by Lev Skuratov on 11.01.2023.
//https://official.contest.yandex.ru/contest/45039/problems/H5/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dijkstra(ll s, ll k, ll n){
    vector<vector<pair<ll, ll>>> arr(n);
    set<pair<ll, ll>> grey;
    vector<ll> w(n, 1e9 + 666);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ll k = 0;
            cin >> k;
            if (i == j || k == -1){
                continue;
            }
            arr[i].push_back({k, j});
        }
    }
    s--;k--;
    vector<bool> used(n, false);
    w[s] = 0;
    grey.insert({0, s});
    while (!grey.empty()){
        auto cur = grey.begin();
        used[cur->second] = true;
        if (cur->second == k){
            cout << cur->first;
            return;
        }
        for (auto e : arr[cur->second]){
            if (used[e.second]){
                continue;
            }
            if (w[e.second] == 1e9+666){
                w[e.second] = e.first + cur->first;
                grey.insert({w[e.second], e.second});
            } else if (e.first + cur->first < w[e.second]){
                grey.erase({w[e.second], e.second});
                w[e.second] = e.first + cur->first;
                grey.insert({w[e.second], e.second});
            }
        }
        grey.erase(cur);
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, s, k;
    cin >> n >> s >> k;
    if (n <= 1) {
        cout << -1;
        return 0;
    }
    dijkstra(s, k, n);
}