//
// Created by Lev Skuratov on 17.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/C3/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;



int main(){
    int n, s, f;
    cin >> n >> s >> f;
    s--;f--;
    vector<vector<pair<ll, ll>>> g(n, vector<pair<ll, ll>> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int c;
            cin >> c;
            g[i][j].second = c;
            g[i][j].first = j;
        }
    }
    

    vector<ll> d(n, 1e9 + 228);
    vector<ll> used(n);

    d[s] = 0;
    while (true){
        int v = -1;
        for (int i = 0; i < n; ++i){
            if (!used[i]){
                if (v == -1 || d[i] < d[v] ){
                    v = i;
                }
            }
        }
        if (v == -1){
            break;
        }
        used[v] = 1;
        for (auto [i, w] : g[v]){
            if (w > -1 && d[i] > d[v] + w){
                d[i] = d[v] + w;
            }
        }
    }
    if (d[f] > 1e9){
        cout << -1;
        return 0;
    }
    cout << d[f];
}