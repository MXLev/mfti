//
// Created by Lev Skuratov on 10.01.2023.
// https://official.contest.yandex.ru/contest/45038/problems/C4/


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

bool operator>(vec f, ll s){
    return f.x > s && f.y > s;
}

bool operator>(vec f, vec s){
    return f.x > s.x && f.y > s.y;
}

bool operator<=(vec f, vec s){
    return f.x <= s.x && f.y <= s.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vec dot, start, end;
    cin >> dot.x >> dot.y >> start.x >> start.y >> end.x >> end.y;
    while (end - start > 1) {
        if (end - start > dot) {
            start = end - start;
        } else if (end - start <= dot) {
            end = end - start;
        }
    }
}
