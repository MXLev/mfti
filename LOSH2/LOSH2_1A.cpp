//
// Created by Lev Skuratov on 31.07.2023.
// https://official.contest.yandex.ru/contest/50873/problems/D1/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ld eps = 0.0000001;

int main(){
    ld n, xa, ya;
    cin >> n >> xa >> ya;
    vector<pair<ld, ld>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    ld sum = 0;
    //atan2([a, b], (a, b))
    //[a, b] = ax * by - ay * bx;
    //(a, b) = ax * bx + ay * by;
    for (int i = 1; i < n; ++i){
        ld ax = arr[i].first - xa, ay = arr[i].second - ya;
        ld bx = arr[i - 1].first - xa, by = arr[i - 1].second - ya;
        sum += atan2(ax * by - ay * bx, ax * bx + ay * by);
    }
    ld ax = arr[0].first - xa, ay = arr[0].second - ya;
    ld bx = arr[n - 1].first - xa, by = arr[n - 1].second - ya;
    sum += atan2(ax * by - ay * bx, ax * bx + ay * by);
    if (abs(sum) <= eps){
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}