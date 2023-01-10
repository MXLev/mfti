//
// Created by Lev Skuratov on 10.01.2023.
// https://official.contest.yandex.ru/contest/45038/problems/E4/

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
    vec A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    ld x0 = (ld)(A.x + B.x + C.x) / 3;
    ld y0 = (ld)(A.y + B.y + C.y) / 3;
    //x0 = (xa + xb + xc)/3 = (2 + 3 + 1)/3 = 2;
    // y0 = (ya + yb + yc)/3 = (1 + 4 + 6)/3 = 3

    cout << setprecision(16);
    cout << x0 << ' ' << y0 << '\n';
}