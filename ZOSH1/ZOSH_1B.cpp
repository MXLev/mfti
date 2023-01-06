//
// Created by Lev Skuratov on 06.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/B1/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> p;
vector<ll> sz;

struct egc{
    ll u, v, w;
};

bool sorter(egc fir, egc sec){
    return fir.w < sec.w;
}

ll g_et(ll a){
    if (p[a] == a){
        return a;
    } else {
        return p[a] = g_et(p[a]);
    }
}

void unite(ll u, ll v){
    u = g_et(u);
    v = g_et(v);
    if (u == v){
        return;
    }
    if (sz[u] > sz[v]){
        swap(u, v);
    }

    p[u] = v;
    sz[u] += sz[v];
}

bool check(ll u, ll v){
    return g_et(u) == g_et(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (n));
    p.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        arr[i].push_back(t);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i){
        p[i] = i;
        sz[i] = 1;
    }
    ll cost = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if (g_et(i) != g_et(j)){
                cost += arr[i][j];
                unite(i, j);
            }
        }
    }

    cout << cost;
}
