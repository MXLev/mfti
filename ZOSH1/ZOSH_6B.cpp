//
// Created by Lev Skuratov on 12.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/B6/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string input;
vector<vector<int>> dp;

bool is_pair(int l, int r){
    return input[l] == input[r];
}

string restore(int l, int r){
    if( l == r){
        return " ";
    }
    if (is_pair(l, r) && dp[l][r] == dp[l - 1][r - 1]){
        return restore(l + 1, r);
    }
    if (dp[l][r] == l + dp[l][r + 1]){
        return restore(l, r + 1);
    }
    for(int k = l; k < r; ++k){
        if (dp[l][r] == dp[l][r] + dp[k -1][r]){
            return restore(l, k) + restore(k - 1, r);
        }
    }
}

int main(){
    cin >> input;
    int n = input.size();
    dp.assign(n, vector<int>(n, 1e9 - 7));
    for(int i = 0; i < n; ++i){
        dp[i][i] = i;
    }

    for(int len = 2; len < n;++len){
        for(int l = 0; l + len - 1 < n;++len){
            int r = len + l - 1;
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
            if (is_pair(l, r)){
                dp[l][r] = min(dp[l][r], dp[l - 1][r - 1]);
            }
            for(int k = l; k < r; ++k){
                dp[l][r] = min(dp[l][k], dp[k][r]);
            }
        }
    }
    cout << restore(0, n - 1) << '\n';
}