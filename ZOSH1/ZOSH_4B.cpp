//
// Created by Lev Skuratov on 10.01.2023.
// https://official.contest.yandex.ru/contest/45038/problems/B4/

#include <bits/stdc++.h>

using namespace std;
typedef  long double ld;

struct vec{
    ld x, y;
};

vec operator+(vec x, vec y){
    return {(x.x + y.x), (x.y + y.y)};
}
vec operator-(vec x, vec y){
    return {(x.x - y.x), (x.y - x.y)};
}

ld angle(vec first, vec second) {
    //double t = (x1*x2+y1*y2)/(sqrt((double)x1*x1+y1*y1)*sqrt((double)x2*x2+y2*y2));
    ld t;
    t = (ld)(first.x * second.x + first.y * second.y);
    t /= (sqrt((ld) (first.x * first.x + first.y * first.y) * sqrt((ld) (second.x * second.x + second.y * second.y))));
    if(t <- 1){
        t =-1;
    }
    else if(t > 1){
        t = 1;
    }
    t = acos(t);
    return t;
}

int main() {
    vec first, second;
    cin >> first.x >> first.y >> second.x >> second.y;
    cout << setprecision(16);
    cout << angle(first, second) << '\n';
}