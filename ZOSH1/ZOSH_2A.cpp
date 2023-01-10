//
// Created by Lev Skuratov on 06.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/A2/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n;
    ll x, y;
    ll z, t;
    vector<ll> arrA(n);

    cin >> x >> y >> arrA[0];
    vector<ll> prefCum;
    prefCum.resize(n + 1);
    prefCum[0] = 0;
    prefCum[1] = arrA[0];
    for (int i = 1; i < n; ++i){
        arrA[i] = (arrA[i - 1] * x + y) % (1 << 16);
        prefCum[i + 1] = prefCum[i] + arrA[i];
    }

    ll res = 0;
    cin >> m;
    if (m == 0){
        cout << 0 << '\n';
        return 0;
    }
    vector<ll> arrB(2 * m);
    vector<ll> arrC(2 * m);
    cin >> z >> t >> arrB[0];
    arrC[0] = arrB[0] % n;
    for (int i = 1; i < 2 * m; ++i) {
        arrB[i] = (arrB[i - 1] * z + t + (1 << 30)) % (1 << 30);
        arrC[i] = arrB[i] % n;
    }
    ll l = 0, r = 0;
    for (int i = 0; i < m; ++i) {
        l = arrC[i * 2];
        r = arrC[i * 2 + 1];
        if (r < l){
            swap(l, r);
        }
        res += (prefCum[r + 1] - prefCum[l]);
    }
    cout << res << '\n';
}
