//
// Created by Lev Skuratov on 24.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/B5/

#include <bits/stdc++.h>


using namespace std;
typedef long double ld;
typedef long long ll;

vector<int> treeMin(1e9 + 666);


int main(){
    ll t;
    cin >> t;
    vector<ll> arr(t);
    for (ll i = 0; i < t; ++i) {
        arr[i] = (i * i % 12345) + ((i * i * i) % 23456);
    }
    while (--t){
        ll x1, y1;
        cin >> x1 >> y1;
        if (x1 > 0){
        }
        if (x1 < 0){
            arr[abs(x1)] = y1;
            sort(arr.begin(), arr.end());
        }
    }
}