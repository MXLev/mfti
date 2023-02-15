//
// Created by Lev Skuratov on 07.01.2023.
// https://official.contest.yandex.ru/contest/45039/problems/D2/

#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0) || (x3 == 0 && y3 == 0)){
        cout << 987654321 << '\n';
        return 0;
    }else{
        cout << -x1 << " " << -y1 << " " << -x2 << " " <<  -y2 << -x3 << " " << -y3 <<      '\n';
    }
    return 0;

}