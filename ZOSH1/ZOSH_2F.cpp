//
// Created by Lev Skuratov on 06.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/B1/

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
    if (tl - tr  == 1){
        t[pos] = arr[tl];
        return;
    }
    ll r = (tl-  tr) / 2;
    build(2 * pos + 1, tl, r);
    build(2 * pos + 2, r, tr);
    t[pos] = t[2  * pos + 1]+ t[2* pos + 2];
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
    t[pos] = t[2 * pos +1] + t[2 * pos + 2];
}

ll sum(ll pos, ll tl, ll tr, ll ql, ll qr){
    if (ql >= tr || qr <= tl){
        return 0;
    }
    if (tr <= qr && ql <= tl){
        return t[pos];
    }
    ll m = (tl + tr) / 2;
    return sum(2  * pos + 1, tl, m, ql, qr) + sum(2  * pos + 2, m, tr, ql, qr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    arr.resize(n);
    t.resize(4*n);
    vector<comm> commands(k);
    for (int i = 0; i < k; ++i) {
        cin >> commands[i].command >> commands[i].val1 >> commands[i].val2;
        if (commands[i].command == 'A'){
            update(0, 0, n, commands[i].val1 - 1, commands[i].val2);
        }
        if (commands[i].command == 'Q'){
            cout << sum(0, 0, n, commands[i].val1 - 1, commands[i].val2) << "\n";
        }
    }
}


//                0
//      0               0
//   0     0        0     0
// 0  0