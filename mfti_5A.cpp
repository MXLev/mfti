//
// Created by Lev Skuratov on 21.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/A5/

#include <bits/stdc++.h>


using namespace std;
typedef long long int ll;

vector<ll> tree;


void update(ll v, ll updateVAL){
    while (v != 0){
        tree[v] += updateVAL;
        v = v >> 1;
    }
}

ll getSum(ll v, ll tl, ll tr, ll left, ll right){
    if (tl == left && tr == right){
        return tree[v];
    }
    if (tl > right || left > tr){
        return 0;
    }
    ll tm = (tl + tr) / 2;
    ll sum1 = getSum(v * 2, tl, tm , left, min(right, tm));
    ll sum2 = getSum(v * 2 + 1, tm + 1, tr, max(left, tm + 1), right);
    return sum1 + sum2;

}

int main(){
    ll n, k;
    cin >> n >> k;
    ll st2 = 1;
    while (st2 < n){
        st2 *= 2;
    }
    tree.resize(2 * st2, 0);
    vector<ll> a(n);
    for (int i = 0; i < k; ++i) {
        char flag;
        ll index, value;
        cin >> flag >> index >> value;
        index--;
        if (flag == 'A'){
            update(st2 + index, value - a[index]);
            a[index] = value;
        } else if (flag == 'Q'){
            value--;
            cout << getSum(1, 0, n, index, value) << '\n';
        }
    }
}