//
// Created by Lev Skuratov on 12.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/C3/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi[s.size() - 1];
}

int main(){
    string s;
    cin >> s;
    if(s.size() == 0){
        return 0;
    }
    ll ans = prefix_function(s);
    cout << s.size() - ans << '\n';
}