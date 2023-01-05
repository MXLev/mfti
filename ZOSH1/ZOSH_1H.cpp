//
// Created by Lev Skuratov on 05.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/H1

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> p;
vector<ll> sz;

struct egc{
    ll u, v, w;
};
struct sec{
    string u;
    ll v, w;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    if (n == 0 || m == 0){
        return 0;
    }
    p.resize(n);
    sz.resize(n);
    vector<egc> arr(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].u >> arr[i].v;
        arr[i].v--;
        arr[i].u--;
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }

    vector<sec> command(k);
    for (int i = 0; i < k; ++i) {
        cin >> command[i].u >> command[i].v >> command[i].w;
        command[i].v--;
        command[i].w--;
    }
    reverse(command.begin(), command.end());
    vector<string> output;
    for (auto i : command){
        if (i.u == "ask"){
            if (g_et(i.v) == g_et(i.w)){
                output.emplace_back("YES");
            } else {
                output.emplace_back("NO");
            }
        } else {
            unite(i.v, i.w);
        }
    }
    reverse(output.begin(), output.end());
    for (int j = 0; j < output.size() ; ++j) {
        cout << output[j] << '\n';
    }
}