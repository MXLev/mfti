//
// Created by Lev Skuratov on 15.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/B1/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];


    vector<int> dp(m + 1, 0);
    dp[0] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll sm = m - p[i]; sm >= 0; sm--) {
            dp[sm + p[i]] = max(dp[sm + p[i]], dp[sm] + c[i]);
        }
    }
    cout << dp[m] << "\n";
    return 0;
}