//
// Created by Lev Skuratov on 07.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/D2/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

vector<pair<ll, ll>> prefCum;

void buildCum (string &s){
    ll counterOPEN = 0, counterClose = 0;
    prefCum[0].first = 0;
    prefCum[0].second = 0;

    for (int i = 1; i < s.size() + 1; ++i) {
        if (s[i - 1] == '('){
            prefCum[i].first = ++counterOPEN;
            prefCum[i].second = counterClose;
        } else {
            prefCum[i].first = counterOPEN;
            prefCum[i].second = ++counterClose;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    prefCum.resize(s.size() + 1);
    buildCum(s);
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        l--;r--;
        if (l > r){
            swap(l, r);
        }
        if (prefCum[r + 1].first - prefCum[l].first == prefCum[r + 1].second - prefCum[l].second){
            cout << 1;
        } else {
            cout << 0;
        }
    }
}