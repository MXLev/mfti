//
// Created by Lev Skuratov on 06.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/A2/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

vector<ll> arr;
void sum(vector<ll> &arr1){
    arr[0] = arr1[0];
    for (int i = 1; i < arr.size(); ++i) {
        arr[i] = arr[i - 1] + arr1[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    ll x, y, a;
    int z, t, b;

    cin >> n >> x >> y >> a;
    vector<ll> arrA(n);
    arr.resize(4 * n);
    for (int i = 0; i < n; ++i){
        // a[i] = a
        arrA[i] = (a * x + y) & ((1 << 16) - 1);
    }
    sum(arrA);

    ll res = 0;
    cin >> m >> z >> t >> b;
    vector<ll> arrB(max(n, m));
    vector<ll> arrC(max(n, m));
    for (int i = 0; i < m; ++i) {
        ll l = b % n;
        b = (b * z + t) & ((1 << 30) - 1);
        ll r = b % n;
        b = (b * z + t) & ((1 << 30) - 1);
        if (l > r){
            swap(l, r);
        }
        res += arr[r] - arr[l];
    }
    cout << res << '\n';
}
