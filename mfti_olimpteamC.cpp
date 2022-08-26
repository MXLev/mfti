//
// Created by Lev Skuratov on 25.08.2022.
// https://official.contest.yandex.ru/contest/39555/problems/A/?success=69757283#7/2016_04_10/coD7chlnRW

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    cin.tie(0);
    ll a,b,k,x;
    cin>>k>>a>>b;
    set<long long> s;
    for(int i=0;i<=k;++i){
        x=i*(-b)+(k-i)*a;
        s.insert(x);
        x=(k-i)*(-b)+i*a;
        s.insert(x);
    }
    cout << s.size();
}
