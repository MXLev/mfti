//
// Created by Lev Skuratov on 18.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/D4/

#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

struct vec{
    ld x, y;
    ld lenght(){
        return sqrt(x * x + y * y);
    }
    vec operator*(ld b) const {
        return {x*b, y*b};
    }
    void operator*=(ld b){
        x*=b;
        y*=b;
    }
};


//v.length()
int main(){
    vec a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y >> c.x >> c.y;

    ld left = 0, right = 1;
    while (right - left > 1e-10){
        ld mid1 = (2 * left + right) / 3;
        ld mid2 = (left + right * 2) / 3;
        vec t = b * mid1;
        vec s = c * mid1;
        if (length(x + y, t) < length(x + y, s)){
            right = mid2;
        } else {
            left = mid1;
        }
    }
    cout << left *  << '\n';
}