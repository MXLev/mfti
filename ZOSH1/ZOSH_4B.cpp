//
// Created by Lev Skuratov on 10.01.2023.
// https://official.contest.yandex.ru/contest/45038/problems/B4/
//http://opentrains.mipt.ru/~ejudge/zosh2023/day4geom.txt

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
typedef  long double ld;

const double PI = 3.1415926535;

struct vec{
    ll x, y;
};

ld length(vec dot){
    return sqrt(pow(dot.x, 2) + pow(dot.y, 2));
}

ll skal(vec left, vec right){
    return (left.x * right.x)  + (left.y * right.y);
}

int main(){
   vec left, right;
   cin >> left.x >> left.y >> right.x >> right.y;
   ld alfa = skal(left, right) / (length(left) * length(right));
   cout << setprecision(16);
   alfa = acos(alfa);
   cout << alfa << '\n';
}