//
// Created by Lev Skuratov on 11.01.2023.
//https://official.contest.yandex.ru/contest/45039/problems/J5/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> arr;

void dijkstra(ll s, ll k, ll n, ll m){
    vector<ll> w(n, 1e9 + 666);
    set<pair<ll, ll>> grey;
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
    ll n, m, s, k;
    cin >> n >> m >> s >> k;
    if (n <= 1) {
        cout << -1;
        return 0;
    }
    arr.resize(n);
    for (ll i = 0; i < m; ++i) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        a--;b--;
        arr[a].push_back({c, b});
        arr[b].push_back({c, a});
    }
    s--;k--;
    dijkstra(s, k, n, m);
}
