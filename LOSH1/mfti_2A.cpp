//
// Created by Lev Skuratov on 16.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/A2/

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
        } else if (used[i] == 1){
            vector<ll> output;
            cout << "YES" << '\n';
            while (i != v){
//                cout << v << ' ';
                output.push_back(v);
                v = p[v];
            }
//            cout << i << '\n';
            output.push_back(i);
            for (ll i = output.size() - 1; i >= 0; --i) {
                cout << output[i] + 1 << ' ';
            }
            exit(0);
        }
    }
    used[v] = 2;

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
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0){
            dfc(i);
        }
    }
    cout << "NO" << '\n';
}