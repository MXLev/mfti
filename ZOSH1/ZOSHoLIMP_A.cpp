//
// Created by Lev Skuratov on 08.01.2023.
// https://official.contest.yandex.ru/contest/45020/problems/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    if (n == 2){
        cout << 1 << ' ' << 1 <<  '\n';
        return 0;
    }
    if (n < 5 || n == 6) {
        cout << -1 << '\n';
        return 0;
    }
    if (n % 2 == 0){
        cout << n - 4 << ' ' << 4;
    } else {
        cout << n - 1 << ' ' << 1 << '\n';
    }
}