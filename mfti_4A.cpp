//
// Created by Lev Skuratov on 18.08.2022.
// https://official.contest.yandex.ru/contest/39326/problems/A4/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;



int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a, b, c;
    cin >> a >> b >> c;
    if (((a * x1) + (b * y1) + c) * ((a * x2) + (b * y2) + c) > 0){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}