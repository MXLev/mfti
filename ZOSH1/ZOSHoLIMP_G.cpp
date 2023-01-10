//
// Created by Lev Skuratov on 08.01.2023.
// https://official.contest.yandex.ru/contest/45020/problems/G/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> prefCum;
vector<char> w;

int main(){
    int n;
    cin >> n;
    prefCum.resize(n);
    vector<char> temp(n);
    for (int i = n - 1; i <= 0; --i) {
        cin >> temp[i];
    }
    reverse(temp.begin(), temp.end());
    w = temp;

}