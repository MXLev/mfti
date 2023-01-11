//
// Created by Lev Skuratov on 11.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/C5/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct towns{
    ll weight;
    vector<ll> related;
};

vector<towns> arr;

ll bfs (ll val){
    if (arr.size() <= val){
        return val;
    }
    for (int i = 0; i < arr[val].related.size(); ++i) {
        arr[i].weight = bfs(val + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    deque<ll> dek;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].weight;
        arr[i].weight--;
        if (arr[i].weight){
            dek.push_back(arr[i].weight);
        } else {
            dek.push_front(arr[i].weight);
        }
    }

    for (int i = 0; i < m; ++i) {
        ll townA, townB;
        cin >> townA >> townB;
        townA--;townB--;
        arr[townA].related.push_back(townB);
        arr[townB].related.push_back(townA);
    }
}