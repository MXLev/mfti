//
// Created by Lev Skuratov on 17.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/B3/


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    vector<ll> who(n);
    for (int i = 0; i < n; ++i) {
        cin >> who[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (who[b] != who[a]){
            g[a].push_back({b, 1 * (1 + a % 2)});
            g[b].push_back({a, 1 * (1 + b % 2)});
        } else {
            g[a].push_back({b, 0});
            g[b].push_back({a, 0});
        }
    }

    set<pair<ll, ll>> s;
    vector<ll> d(n, 1e9 + 666);
    vector<ll> p(n);
    d[0] = 0;
    s.insert({0, 0});
    while (s.size() > 0){
        ll v = s.begin() -> second;
        s.erase(s.begin());
        for (auto [i, w] : g[v]){
            if (d[v] + w < d[i]){
                s.erase({d[i], i});
                d[i] = d[v] + w;
                s.insert({d[i], i});
                p[i] = v;
            }
        }
    }

    vector<ll> output;
    output.push_back(n - 1);
    ll v = n - 1;
    for (int i = n - 1; i > 0; i = p[i]) {
        output.push_back(p[i]);
    }
    reverse(output.begin(), output.end());

    if (d[n - 1] == -1){
        cout << "impossible" << '\n';
        return 0;
    }

    cout << d[n - 1] << ' ' << output.size() << '\n';
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] + 1 << ' ';
    }
}