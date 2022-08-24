//
// Created by Lev Skuratov on 18.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/D4/

#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

struct vec{
    ld x, y;
    ld length() const{
        return sqrt(x * x + y * y);
    }

    void operator*=(ld b){
        x *= b;
        y *= b;
    }

};

bool operator<(vec x, vec b){ return x.x < b.x && x.y < b.y;}

vec operator*(vec x, ld b){ return {x.x * b, x.y * b};}

vec operator+(vec x, ld b){ return {x.x + b, x.y + b};}

//v.length()
int main(){
    vec a = {0, 0}, b = {0, 0}, c = {0, 0};
    cin >> a.x >> a.y;
    cin >> b.x >> b.y >> c.x >> c.y;

    ld left = 0, right = 1;
    while (right - left > 1e-10){
        ld mid1 = (2 * left + right) / 3;
        ld mid2 = (left + right * 2) / 3;

        if (){
            right = mid2;
        } else {
            left = mid1;
        }
    }
    cout << setprecision(5) << left * right << '\n';
}