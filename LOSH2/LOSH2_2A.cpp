//
// Created by Lev Skuratov on 01.08.2023.
// https://official.contest.yandex.ru/contest/50873/problems/E2/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> cur;
vector<bool> used;

bool dfs(vector<vector<ll>> &arr, ll point){
    if (used[point]){
        return !used[point];
    }
    used[point] = true;
    for (int i = 0; i < arr[point].size(); ++i) {
        ll to = arr[point][i];
        if (cur[to] == -1 || dfs(arr, cur[to])){
            cur[to] = point;
            return true;
        }
    }
    return false;
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n);
    for (int i = 0; i < n; ++i) {
        ll cur = 1;
        while(cur){
            cin >> cur;
            arr[i].push_back(cur - 1);
        }
        arr[i].pop_back();
    }
    cur.assign(m, -1);
    for (ll cur = 0; cur < n; ++cur) {
        used.assign(n, false);
        dfs(arr, cur);
    }
    ll sum = 0;
    for (ll i = 0; i < m; ++i){
        if (cur[i] != -1){
            sum++;
        }
    }
    cout << sum << '\n';
    for (ll i = 0; i < m; ++i){
        if (cur[i] != -1){
            cout << cur[i] + 1 << ' ' << i + 1 << '\n';
        }
    }
}