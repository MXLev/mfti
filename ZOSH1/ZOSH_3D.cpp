//
// Created by Lev Skuratov on 07.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/D3/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

int main(){
    string t;
    cin >> t;
    vector<ll> p(t.size());
    p[0] = 0;
    for (int i = 1; i < t.size(); ++i) {
        ll j = p[i - 1];
        while (j > 0 && t[j] != t[i]){
            j = p[j  - 1];
        }
        if (t[i] == t[j]) {
            j++;
        }
        p[i] = j;
    }
    for (int i = 0; i < t.size(); ++i) {
        cout << p[i] << ' ';
    }
}
