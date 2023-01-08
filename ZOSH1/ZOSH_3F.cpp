//
// Created by Lev Skuratov on 07.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/C3/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

ll mod = 1e9 + 21;
vector<ll> h;
vector<ll> powB;
const ll con = 26;

//void powBcalc(ll b, ll size){
//    powB[0] = 1;
//    for (int i = 1; i < size; ++i) {
//        powB[i] = powB[i - 1] * b;
//    }
//}

ll norm(ll a){
    a %= mod;
    if (a < 0){
        a += mod;
    }
    return a;
}

bool isEqual(ll a, ll b, ll c, ll d){
    ll first = 0, second = 0;
    first = h[a] * powB[a];
}

vector<long long> build(string a) {
    vector<long long> r(a.size() + 1);
    powB.resize(a.size() + 1);
    powB[0] = 1;
    r[0] = 0;
    for (int i = 1; i < powB.size(); i++) {
        powB[i] = (powB[i - 1] * con) % mod;
    }
    for (int i = 1; i < r.size(); i++) {
        r[i] = norm((a[i - 1] - 'a' + 1) + r[i - 1] * con);
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int m;
    cin >> m;
    h = build(s);
    for (int i = 0; i < m; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        if (isEqual(a, b, c, d)){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}