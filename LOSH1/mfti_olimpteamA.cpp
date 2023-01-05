//
// Created by Lev Skuratov on 25.08.2022.
// https://official.contest.yandex.ru/contest/39555/problems/G/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'z'){
            s[i] = 'a';
        } else if (s[i] == 'Z'){
            s[i] = 'A';
        } else {
            s[i] += 1;
        }
    }
    cout << s << '\n';
}