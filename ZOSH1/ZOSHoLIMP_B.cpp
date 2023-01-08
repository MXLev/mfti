//
// Created by Lev Skuratov on 08.01.2023.
// https://official.contest.yandex.ru/contest/45020/problems/B/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int k;
    cin >> k;
    string output;
    for (int i = 0; i < k; ++i) {
        if (i % 2 == 0){
            output += '9';
        } else {
            output += '8';
        }
    }
    cout << output << '\n';
}