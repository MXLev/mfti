//
// Created by Lev Skuratov on 08.01.2023.
// https://official.contest.yandex.ru/contest/45020/problems/E/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n, ans = 0;
    for (int i = 0; i < 130; ++i) {
        cin >> n;
        if (n == 0){
            cout << "! " << ans << '\n';
            return 0;
        }
        ans += n;
        cout << "? " << n << '\n';
        cout << flush;
    }

}