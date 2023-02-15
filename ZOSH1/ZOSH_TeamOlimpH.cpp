#include <bits/stdc++.h>
using namespace std;


void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastio();
    int n, m;
    cin >> n >> m;
    vector<int> mipt(n); // mom
    vector<int> hse(n); // dad
    for (int i = 0; i < n; ++i) {
        cin >> mipt[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> hse[i];
    }

    sort(mipt.rbegin(), mipt.rend());
    sort(hse.rbegin(), hse.rend());

    vector<int> a(n);
    vector<int> b(n);
    if (mipt[0] >= m){
        cout << "MIPT" << '\n';
        return 0;
    }
    if(hse[0] - mipt[0] >= m){
        cout << "HSE\n";
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        mipt[i] += mipt[i - 1];
        hse[i] += hse[i - 1];
        if (mipt[i] - hse[i - 1] >= m){
            cout << "MIPT\n";
            return 0;
        } else if (hse[i] - mipt[i - 1] >= m){
            cout << "HSE\n";
            return 0;
        } else if (mipt[i] - hse[i] >= m){
            cout << "MIPT\n";
            return 0;
        } else if (hse[i] - mipt[i] >= m){
            cout << "HSE\n";
            return 0;
        }
    }
    cout << "NO" << '\n';
//    a[0] = mipt[0];
//    if (a[0] > m) {
//        cout << "MIPT" << '\n';
//        return 0;
//    }
//    b[0] = hse[0];
//    if (abs(a[0] - b[0]) > m) {
//        if (a[0] - b[0] > 0) {
//            cout << "MIPT" << '\n';
//            return 0;
//        } else {
//            cout << "HSE" << '\n';
//            return 0;
//        }
//    }
//    for (int i = 1; i < n; ++i) {
//        a[i] = a[i - 1] + mipt[i];
//        b[i] = b[i - 1] + hse[i];
//        if (abs(a[i] - b[i]) >= m) {
//            if (a[i] - b[i] > 0) {
//                cout << "MIPT" << '\n';
//                return 0;
//            } else {
//                cout << "HSE" << '\n';
//                return 0;
//            }
//        }
//    }
//
//    cout << "NO" << '\n';
//
//
//    return 0;
}