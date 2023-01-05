//
// Created by Lev Skuratov on 16.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/B2/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> used;
vector<vector<ll>> g;
vector<ll> p;


void dfc(ll v){
    used[v] = 1;
    for (int i : g[v]) {
        if (used[i] == 0){
            p[i] = v;
            dfc(i);
        } else if (used[i] == 1 && p[v] != i){
            cout << "NO" << '\n';
            exit(0);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    p.resize(n);
    used.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0 && !flag) {
            dfc(i);
            flag = true;
        } else if (used[i] == 0 && flag){
            cout << "NO" << '\n';
            return 0;
        }
    }
   cout << "YES" << '\n';
}