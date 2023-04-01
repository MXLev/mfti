//
// Created by Beast on 29.03.2023.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=29ec6d560c934466&action=141&prob_id=3

#include <iostream>
#include <vector>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastio();
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        cin >> x;
        if (x < n){
            count++;
        }
    }
    cout << count << '\n';
}