//
// Created by Lev Skuratov on 07.01.2023.
//https://official.contest.yandex.ru/contest/45039/problems/A3/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

int main(){
    string text, s;
    cin >> text >> s;
    string t = s + '#' + text;
    ll n = t.size();
    vector<ll> p(n);
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        ll j = p[i - 1];
        while (j > 0 && t[j] !=t[i]){
            j = p[j  - 1];
        }
        if (t[i] == t[j]) {
            j ++;
        }
        p[i] = j;
    }
    int counter = 0;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (p[i] == s.size()){
            counter++;
            pos.push_back(i - (s.size()* 2));
        }
    }
    cout << counter << '\n';
    for (int i = 0; i < pos.size(); ++i) {
        cout << pos[i] + 1   << ' ';
    }
    cout << '\n';
}