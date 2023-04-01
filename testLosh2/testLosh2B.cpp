//
// Created by Beast on 29.03.2023.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=29ec6d560c934466&action=141&prob_id=2

#include <iostream>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastio();
    int n, p;
    cin >> n >> p;
    if (n * (1.0/12.0) >= p){
        cout << 1 << '\n';
    } else if (n * (2.0/5.0) >= p){
        cout << 2 << '\n';
    } else {
        cout << 0 << '\n';
    }
}