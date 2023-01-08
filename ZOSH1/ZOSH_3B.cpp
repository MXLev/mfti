//
// Created by Lev Skuratov on 07.01.2023.
//  https://official.contest.yandex.ru/contest/45039/problems/B3/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

vector<ll> z_func(vector<ll> &s, ll n) {
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    vector<ll> ans = z_func(input, n);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}