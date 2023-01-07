//
// Created by Lev Skuratov on 07.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/D2/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

vector<ll> arr;

void buildSum (string &s){
    ll counter1 = 0, counter2 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '('){
            arr[i] = abs(++counter1 - counter2);
        } else {
            arr[i] = abs(++counter2 - counter1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    arr.resize(s.size());
    buildSum(s);
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        if (l > r){
            swap(l, r);
        }
        if (arr[r] - arr[l] == 0){
            cout << 1;
        } else {

            cout << 0;
        }
    }
}