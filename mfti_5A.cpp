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

void update(ll v, ll lt, ll rt, ll updateVAL, ll updateIND){
    while (v != 0){
        tree[v] = tree[v] - updateVAL;
        v--;
        v = v >> 1;
    }
}

ll getSum(ll v, ll tl, ll tr, ll left, ll right){
    push(v, tl, tr);
    if (tl == left && tr == right){
        return tree[v];
    }

}

int main(){
    ll n, k;
    cin >> n >> k;
    tree.resize(4 * n);
    fill(tree.begin(), tree.end(), 0);
    prom.resize(4 * n);
    fill(tree.begin(), tree.end(), 0);

    for (int i = 0; i < k; ++i) {
        char flag;
        ll index, value;
        cin >> flag >> index >> value;
        if (flag == 'A'){
            tree.push_back(value);
        } else if (flag == 'Q'){
            cout << tree[i] << '\n';
        }
    }
}