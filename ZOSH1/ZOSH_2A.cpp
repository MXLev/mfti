//
// Created by Lev Skuratov on 06.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/A2/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr;
ll sum(vector<ll> &arr1){
    arr[0] = arr1[0];
    for (int i = 1; i < arr.size(); ++i) {
        arr[i] = arr[i - 1] + arr1[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int x, y, a;
    int z, t, b;

    cin >> n >> x >> y >> a;
    vector<ll> arrA(4 * n);
    arrA[0] = a;
    arr.resize(4 * n);
    for (int i = 1; i <= n; ++i){
        // a[i] = a
        a = (a * x + y) & ((1 << 16) - 1);
        arrA[i] = x * arrA[i - 1] + y;
    }
    sum(arrA);

    ll res = 0;
    cin >> m >> z >> t >> b;
    vector<ll> arrB(4 * max(n, m));
    vector<ll> arrC(4 * max(n, m));
    arrB[0] = b;
    for (int i = 1; i <= m; ++i) {
        ll l = b % n;
        b = (b * z + t) & ((1 << 30) - 1);
        ll r = b % n;
        b = (b * z + t) & ((1 << 30) - 1);
        if (l > r){
            swap(l, r);
        }
        arrB[i] = z * arrB[i - 1] + t;
        arrC[i] = arrB[i] % n;
        res += arr[min(arrC[2 * i], arrC[2 * i + 1])]  - arr[max(arrC[2 * i], arrC[2* i + 1])];
    }
    cout << res << '\n';
}
