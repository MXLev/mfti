//
// Created by Lev Skuratov on 17.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/A3/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;



int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
}