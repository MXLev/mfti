//
// Created by Lev Skuratov on 17.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/C3/

#include <iostream>
#include <deque>
#include <vector>

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
        } else {
            g[a].push_back({b, 0});
        }
    }

    deque<ll> q;
    vector<ll> d(n, -1);
    vector<ll> used(n);

    d[0] = 0;
    while (true){
        int v = -1;
        for (int i = 0; i < n; ++i){
            if (!used[i]){
                if (v == -1 || d[i] < d[v]){
                    v = i;
                }
            }
        }
        if (v == -1){
            break;
        }
        used[v] = 1;
        for (auto [i, w] : g[v]){
            if (d[i] > d[v] + w){
                d[i] = d[v] + w;
            }
        }
    }
    cout << *min_element(d.begin(), d.end()) << ' ' << '\n';
}