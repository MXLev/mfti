//
// Created by Lev Skuratov on 18.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/B4/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;



int main(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll a = y1 - y2;
    ll b = x2 - x1;
    ll c = -y1 * x2 + y2 * x1;
    cout << a << ' ' << b << ' ' << c << '\n';
}