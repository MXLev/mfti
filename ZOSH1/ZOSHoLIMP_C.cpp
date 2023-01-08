//
// Created by Lev Skuratov on 08.01.2023.
// https://official.contest.yandex.ru/contest/45020/problems/C/

#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll counter = 0;
    for (int i = floor(sqrt(n) + 0.5); i < n; ++i) {
        if (n / i == n % i){
            counter++;
            cout << i << ' ';
        }
    }
    cout << '\n' << counter << '\n';
}