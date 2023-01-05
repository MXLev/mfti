//
// Created by Lev Skuratov on 05.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/A1

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

int get(ll &a){
    if (p[a] == a){
        return a;
    } else {
        return p[a] = get(p[a]);
    }
}

void unite(ll u, ll v){
    u = get(u);
    v = get(v);
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
    return get(u) == get(v);
}

int main(){
    ll n, m;
    cin >> n >> m;
    p.resize(n);
    sz.resize(n);
    vector<egc> arr(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].u >> arr[i].v >> arr[i].w;
        --arr[i].v;
        --arr[i].u;
    }
    sort(arr.begin(), arr.end(), sorter);
    for (int i = 0; i < n; ++i){
        p[i] = i;
        sz[i] = 1;
    }
    ll cost = 0;
    for (int i = 0; i < m; ++i) {
        if (get(arr[i].u) != get(arr[i].v)){
            cost += arr[i].w;
            unite(arr[i].u, arr[i].v);
        }
    }

    cout << cost;
}