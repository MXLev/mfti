//
// Created by Lev Skuratov on 16.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/C2/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;



int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g;
    vector<vector<ll>> _g;
    vector<ll> p;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        _g[b - 1].push_back(a - 1);
    }

    vector<ll> st;
    while (st.size()){
        ll v = st.back();
        for (ll i : _g[v]) {
            if (i == 0){
                st.push_back(i);
                _g.pop_back();
            }
        }
    }
    
}
