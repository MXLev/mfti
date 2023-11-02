//
// Created by Lev Skuratov on 12.01.2023.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(ll n){
    if (n == 1){
        return 2;
    } else {
        return f(n - 1) * pow((n % 5), 3) / pow(n % 7, 3);
    }
}

int main(){
    cout << f(1025) / f(1030);
}