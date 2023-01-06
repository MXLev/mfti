//
// Created by Lev Skuratov on 06.01.2023.
//https://official.contest.yandex.ru/contest/45039/problems/H2/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<ll> arr;
vector<ll> t;

struct comm{
    char command;
    ll val1, val2;
};

void build (ll pos, ll tl, ll tr){
    if (tr - tl <= 1){
        t[pos] = arr[tl];
        return;
    }
    ll r = (tr -  tl) / 2;
    build(2 * pos + 1, tl, r);
    build(2 * pos + 2, r, tr);
    t[pos] = t[2  * pos + 1] + t[2* pos + 2];
}

void update (ll pos, ll tl, ll tr,ll qpos, ll newVal) {
    if (qpos < tl || qpos >= tr) {
        return;
    }
    if (tr- tl == 1){
        t[pos] = newVal;
        return;
    }
    ll m = (tl + tr) / 2;
    update(2 * pos + 1, tl, m, qpos, newVal);
    update(2 * pos + 2, m, tr, qpos, newVal);
    t[pos] = t[2 * pos + 1] + t[2 * pos + 1];
}

ll sum(ll pos, ll tl, ll tr, ll ql, ll qr){
    if (ql >= tr || qr <= tl){
        return 0;
    }
    if (tr >= qr && ql >= tl){
        return t[pos];
    }
    ll m = (tl + tr) / 2;
    return sum(pos, tl, m, ql, qr) + sum(pos, m +  1, tl, ql, qr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arr.resize(n);
    t.resize(n * 4);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    build(1, 0, n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        bool command;
        cin >> command;
        if (command){
            ll l, r;
            cin >> l >> r;
            if (l % 2 == 0){
                cout << sum(0, 0, n - 1, l, r) * -1 << '\n';
            } else {
                sum(0, 0, n - 1, l, r);
            }
        } else {
            int i, j;
            cin >> i >> j;
            update(0, 0, n, i - 1, j);
        }
    }
}