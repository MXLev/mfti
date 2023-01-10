//
// Created by Lev Skuratov on 10.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/K3/

#include <bits/stdc++.h>


using namespace std;
typedef  long long ll;
typedef  long double ld;

struct vec{
    ll x, y;
};

vec operator+(vec x, vec y){
    return {(x.x + y.x), (x.y + y.y)};
}
vec operator-(vec x, vec y){
    return {(x.x - y.x), (x.y - x.y)};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vec first, second;
    cin >> first.x >> first.y >> second.x >> second.y;
    cout << setprecision(17);
    cout << sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2)) << '\n';
}