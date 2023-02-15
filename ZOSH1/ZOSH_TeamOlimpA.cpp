#include <bits/stdc++.h>
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
    if (n == 1)
        cout << 2 << '\n';
    else
        cout << 4 << '\n';

    return 0;
}