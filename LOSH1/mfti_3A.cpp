//
// Created by Lev Skuratov on 17.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/A3/

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
            g[a].push_back({b, 1});
            g[b].push_back({a, 1});
        } else {
            g[a].push_back({b, 0});
            g[b].push_back({a, 0});
        }
    }

    deque<ll> q;
    vector<ll> d(n, -1);
    vector<ll> p(n);
    vector<ll> used(n);
    q.push_front(0);
    d[0] = 0;
    vector<ll> output;
    while (q.size() > 0){
        ll v = q.front();
        q.pop_front();
        used[v] = 1;
        for (auto [i, w] : g[v]) {
            if (!used[i]){
                if (w == 0){
                    q.push_front(i);
                    d[i] = d[v];
                } else if (w == 1){
                    q.push_back(i);
                    d[i] = d[v] + 1;
                }

                used[i] = 1;
                p[i] = v;
            }
        }
    }
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