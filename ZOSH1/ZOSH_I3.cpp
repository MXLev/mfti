//
// Created by Lev Skuratov on 12.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/I3/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> d1 (n);
    unsigned long long ans = 0;
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) ++k;
        d1[i] = k;
        if (i + k - 1 > r)
            l = i - k + 1, r = i + k - 1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }

    for (int i = 0; i < n; ++i) {
        ans += d1[i] + d2[i];
    }

    cout << ans - s.size();
}