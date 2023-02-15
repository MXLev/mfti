//
// Created by Lev Skuratov on 11.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/C5/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll const INF = 1e9-7;

vector<vector<pair<ll, ll>>> arr;
vector<vector<ll>> path;
ll minCost = INF;

void bfs(int s, ll n) {
    vector<ll> dist(n, INF);
    dist[s] = 0;
    deque<ll> pending;
    pending.push_back(s);
    vector<bool> used(n);
    path.resize(n);

    while (!pending.empty()) {
        ll v = pending.front();
        pending.pop_front();
        for (auto&& [to, w] : arr[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                minCost = min(minCost, dist[to]);
                path[to] = path[v];
                path[to].push_back(v);
                if (w == 0) {
                    pending.push_front(to);
                } else {
                    pending.push_back(to);
                }
            }
        }
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    arr.resize(n);
    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
        temp[i]--;
    }
    for (int i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        arr[a].push_back({b, temp[i]});
    }
    bfs(0, n);

    cout << minCost << ' ' << path[n - 1].size() << '\n';
//    for (int i = 0; i < path.size(); ++i) {
//        cout << path[n - 1][i];
//    }
}