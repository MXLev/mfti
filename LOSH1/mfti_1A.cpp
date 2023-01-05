//
// Created by Lev Skuratov on 15.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> s;

    vector<int> dp(s + 1, 1000000000);
    dp[0] = 0;
    vector<int> p(s + 1);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i <= s; ++i) {
            if (i + arr[j] <= s && dp[i + arr[j]] > dp[i]) {
                dp[i + arr[j]] = dp[i] + 1;
                p[i + arr[j]] = arr[j];
            }
        }
    }
    if (dp[s] == 1000000000){
        cout << "-1\n";
        return 0;
    }
    cout << dp[s] << '\n';
    int cur = s;
    while (cur > 0){
        cout << p[cur] << ' ';
        cur -= p[cur];
    }
}