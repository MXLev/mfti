//
// Created by Lev Skuratov on 18.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/C4/

#include <bits/stdc++.h>


using namespace std;
typedef long double ld;

int main(){
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld _a = sqrt(x1 * x1 + y1 * y1);
    ld _b = sqrt(x2 * x2 + y2 * y2);
    ld output = (x1 * x2 + y1 * y2) / (_a * _b);
    cout << setprecision(7) << acos(output) << '\n';
}