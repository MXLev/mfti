// test failed -rep
// Created by Lev Skuratov on 08.01.2023.
// https://official.contest.yandex.ru/contest/45020/problems/D/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){//72981//4
    ll p;
    cin >> p;
    if (p < 3 || p == 4){
        cout << -1 << '\n';
        return 0;
    }
    ll a = sqrt(p), b = 0, c = 0;
    b = floor(((p - a) / 2.0) + 0.5);
    c = (p - a) / 2;
    cout << a << ' ' << b << ' ' << c << '\n';


    if (a + b + c == p){
        cout << "TRUE\n";
    } else {
        cout << "WTF\n";
    }
}