//
// Created by Lev Skuratov on 08.01.2023.
// https://official.contest.yandex.ru/contest/45020/problems/F/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k ;
    vector<ll> copy_past(n);
    vector<ll> original(n);
    for (int i = 0; i < n; ++i) {
        cin >> copy_past[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
    }
    ll diff = 0;
    for (int i= 0; i < n; ++i) {
        diff += n + i * abs(copy_past[i] - original[i]);
    }
    cout << diff << '\n';
}