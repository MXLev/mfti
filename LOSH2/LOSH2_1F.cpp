//
// Created by Lev Skuratov on 31.07.2023.
//https://official.contest.yandex.ru/contest/50873/problems/F1/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

//bool isIN(ll x1, ll y1, ll x3, ll y3, ll xf, ll yf){
//    ll x2 = x1, y2 = y3;
//    ll x4 = x3, y4 = y1;
//    if (x1 > x3){
//        x1 = x3;
//        x3 = x2;
//        x2 = x1;
//        x4 = x3;
//    }
//    if (y1 > y3){
//        y1 = y3;
//        y3 = y4;
//        y2 = y3;
//        y4 = y1;
//    }
//    bool xtrue = false;
//    bool ytrue = false;
//    if (xf < x3 && xf > x1){
//        xtrue = true;
//    }
//    if (yf < y3 && yf > y1){
//        ytrue = true;
//    }
//    return xtrue && ytrue;
//}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll> (4));
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
//
//        ll x2 = arr[i][0], y2 = arr[i][3];
//        ll x4 = arr[i][3], y4 = arr[i][1];
//        if (arr[i][0] > arr[i][3]){
//            arr[i][0] = arr[i][3];
//            arr[i][2] = x2;
//        }
//        if (arr[i][1] > arr[i][3]){
//            arr[i][1] = arr[i][3];
//            arr[i][3] = y4;
//        }
    }
    ll ansX1 = arr[0][0], ansY1 = arr[0][1];
    ll ansX2 = arr[0][2], ansY2 = arr[0][3];
    for(int i = 1; i < n; ++i){
        //ansX = min(arr[i][2], arr[i][0]) - max(arr[i - 1][2], arr[i - 1][0]);
        //ansY = min(arr[i][3], arr[i][1]) - max(arr[i - 1][3], arr[i - 1][1]);
        ansX1 = max(ansX1, arr[i][0]);
        ansY1 = max(ansY1, arr[i][1]);
        ansX2 = min(ansX2, arr[i][2]);
        ansY2 = min(ansY2, arr[i][3]);
        if (ansX1 <= ansX2 && ansY1 <= ansY2) {
            continue;
        }
        else {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ansX1 << ' ' << ansY1 << ' ' << ansX2 << ' ' << ansY2 << '\n';
}