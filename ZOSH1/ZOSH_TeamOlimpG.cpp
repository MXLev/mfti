#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int divisors[2];
    divisors[0] = -1;
    for (int i = 2; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) {
            divisors[0] = i;
            divisors[1] = n / i;
            break;
        }
    }
    if (divisors[0] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    int sum = divisors[0] + divisors[1];
    int amount_of_1 = n - sum;

    if (n == 2) {
        cout << -1 << '\n';
        return 0;
    }
    if (amount_of_1 == 0) {
        cout << 2 << '\n';
        cout << divisors[0] << ' ' << 1 << '\n' << divisors[1] << ' ' << 1 << '\n';
    } else {
        cout << 3 << '\n';
        cout << divisors[0] << ' ' << 1 << '\n' << divisors[1] << ' ' << 1 << '\n' << 1 << ' ' << amount_of_1 << '\n';
    }



    return 0;
}