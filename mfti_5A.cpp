//
// Created by Lev Skuratov on 21.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/A5/

#include <bits/stdc++.h>


using namespace std;
typedef long long int ll;

vector<ll> tree;
vector<ll> prom;

void push(ll v, ll lt, ll rt){
    tree[v] += prom[v] * (rt - lt + 1);
    prom[2 * v + 1] += prom[v];
    prom[2 * v + 2] += prom[v];
    prom[v] = 0;
}

void update(ll v, ll updateVAL){
    while (v != 0){
        tree[v] += updateVAL;
        v--;
        v = v >> 1;
    }
    tree[0] = tree[0] - updateVAL;
}

ll getSum(ll v, ll tl, ll tr, ll left, ll right){
    push(v, tl, tr);
    if (tl == left && tr == right){
        return tree[v];
    }
    if (tl > left || tr < right){
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
    tree.resize(4 * n);
    fill(tree.begin(), tree.end(), 0);
    prom.resize(4 * n);
    fill(tree.begin(), tree.end(), 0);
    vector<ll> a(n);
    ll st2 = 1;
    for (int i = 0; i < k; ++i) {
        char flag;
        ll index, value;
        cin >> flag >> index >> value;
        if (flag == 'A'){
            update(st2 + index, value - a[index]);
            a[index] = value;
        } else if (flag == 'Q'){
            cout << getSum(1, 1, n, index, value);
        }
    }
}