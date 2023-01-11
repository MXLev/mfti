//
// Created by Lev Skuratov on 11.01.2023.
//https://official.contest.yandex.ru/contest/45039/problems/C5/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> arr;

void dijkstra(ll s, ll k, ll n, ll m){
    vector<ll> w(n, 1e9 + 666);
    set<pair<ll, ll>> grey;
    vector<bool> used(n, false);
    vector<ll> answ;
    vector<vector<ll>> prev(n + 1);
    w[s] = 0;
    grey.insert({0, s});
    while (!grey.empty()){
        auto cur = grey.begin();
        answ.push_back(cur->second);
        used[cur->second] = true;
        if (cur->second == k){
            if (prev[cur->second].size() == 1){
                cout << -1 << '\n';
                return;
            }
            cout << cur->first << '\n';
            prev[k].push_back(k);
            for (int i = 0; i < prev[cur->second].size(); ++i) {
                cout << prev[cur->second][i] + 1 << ' ';
            }
            return;
        }
        for (auto e : arr[cur->second]){
            if (used[e.second]){
                continue;
            }
            grey.erase({w[e.second], e.second});
            w[e.second] = e.first + cur->first;
            grey.insert({w[e.second], e.second});
            prev[e.second] = prev[cur->second];
            prev[e.second].push_back(cur->second);
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

