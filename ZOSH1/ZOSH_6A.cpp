//
// Created by Lev Skuratov on 12.01.2023.
//https://official.contest.yandex.ru/contest/45039/problems/A6//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<double>> dp;
vector<int> a;

void build(int n){
    for (int i=0; i < n;++i){
        dp[i][i] = a[i];
    }
}

double calc(int n){
    for(int len = 2; len <= n; ++len){
        for (int l = 0; l + len - 1 < n;++l){
            int r = l + len - 1;
            for (int mid = l; mid < r; ++mid){
                double p1 = dp[l][mid];
                double p2 = dp[mid + 1][r];
                double now = (p1 + p2) / 2;
                if (now > dp[l][r]){
                    dp[l][r] = now;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp.resize(n, vector<double> (n));
    build(n);
    cout << setprecision(16);
    cout << calc(n) << '\n';
}