//
// Created by Lev Skuratov on 09.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/E2/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    ll k;
    cin >> k;
    for (ll i = 0; i < k; ++i) {
        ll l , r;
        cin >> l >> r;
        r--;l--;
        for (ll j = n - 1; j >= 0; --j) {
            if (l <= arr[j].second && arr[j].second <= r){
                cout << arr[j].first << ' ' << arr[j].second + 1 << '\n';
                break;
            }
        }
    }
}