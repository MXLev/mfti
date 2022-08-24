//
// Created by Lev Skuratov on 22.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/B6/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    set<int> s;
    for (int i = 1; i <= 200000; ++i){
        s.insert(i);
    }
    for (int q = 0; q < t; ++q) {
        int a;
        cin >> a;
        if (a > 0){
            auto b = s.lower_bound(a);
            cout << *b << '\n';
            s.erase(b);
        } else if (a < 0 && a < *s.begin()){
            s.insert(abs(a));
        }
    }
}