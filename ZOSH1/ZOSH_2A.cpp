//
// Created by Lev Skuratov on 06.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/A2/

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
    build(2 * pos, tl + 1, r);
    build(2 * pos + 2, r, tr);
    t[pos] = t[2  * pos + 1]+ t[2* pos + 1];
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
    int n, m;
    int x, y, a;
    int z, t, b;

    cin >> n >> x >> y >> a;
    for (int i = 0; i < n; ++i)  {
        // a[i] = a

        a = (a * x + y) & ((1 << 16) - 1);
    }

    ll res = 0;
    cin >> m >> z >> t >> b;
    for (int i = 0; i < m; ++i)
    {
        int l = b % n; b = (b * z + t) & ((1 << 30) - 1);
        int r = b % n; b = (b * z + t) & ((1 << 30) - 1);
        if (l > r)
            swap(l, r);
        // запрос с параметрами l, r
    }
}