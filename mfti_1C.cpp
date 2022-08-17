//
// Created by Lev Skuratov on 16.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/C1/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<ll> dp(n);
    dp[0] = 1;
    ll mx = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] < arr[i]){
                dp[i]++;
            }
            if (mx < dp[i]){
                mx = dp[i];
            }
        }
    }
    cout << mx << '\n';
}