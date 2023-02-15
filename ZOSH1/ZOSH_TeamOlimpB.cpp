//
// Created by Lev Skuratov on 13.01.2023.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, w, d;
    cin >> n >> w >> d;
    vector<ll> sanitaizer(n);
    set<ll> ananas;
    for (int i = 0; i < n; ++i) {
        cin >> sanitaizer[i];
        ananas.insert(sanitaizer[i]);
    }
    if (ananas.size() > w){
        cout << -1 << '\n';
        return 0;
    }

    map<ll, ll> mapa;
    for (int i = 0; i < n; ++i) {
        mapa[sanitaizer[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (mapa[sanitaizer[i]] > d){
            cout << -1 << '\n';
            return 0;
        }
    }
    for(auto i: ananas){
        cout << i << ' ';
    }
    cout << '\n';
    for(auto i : mapa){
        cout << i.second << ' ';
    }
}