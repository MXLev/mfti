//
// Created by Lev Skuratov on 01.08.2023.
// https://official.contest.yandex.ru/contest/50873/problems/B2/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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
    ll n;
    cin >> n;
    string word;
    cin >> word;
    ll m = word.size();
    used.assign(n, false);
    vector<vector<ll>> arr(n);
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < m; ++j) {
            auto pos = input.find(word[j]);
            if (pos != -1){
                arr[i].push_back(j);
            }
        }
    }
    cur.assign(m, -1);
    for (ll cur = 0; cur < n; ++cur) {
        used.assign(n, false);
        dfs(arr, cur);
    }
    for (int i = 0; i < m; ++i) {
        if (cur[i] == -1){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        cout << cur[i] + 1 << ' ';//kurochka
    }
}
