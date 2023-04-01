//
// Created by Beast on 29.03.2023.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=29ec6d560c934466&action=141&prob_id=4

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
    int last = 0;
    int count = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < last){
            count++;
        } else {
            count = 1;
        }
        cout << count << '\n';
        last = x;
    }
}
