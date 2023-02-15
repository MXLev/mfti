//
// Created by Lev Skuratov on 13.01.2023.
//  https://official.contest.yandex.ru/contest/45039/problems/D6/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> fib = { 0, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377,
                    610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578,
                    5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};

bool gen(vector<bool> &arr, ll n, ll k, ll count, bool a) {
    if (arr.size() == n) {
        if (k == count) {
            for (auto e : arr)cout << e;
            return true;
        }
        return false;
    }
    if (a) {
        arr.push_back(0);
        if (gen(arr, n, k, count, false)){
            return true;
        }
        else {
            return false;
        }
    }
    else if (fib[n - arr.size() + 2] + count <= k) {
        count += fib[n - arr.size() + 2];
        arr.push_back(true);
        if(gen(arr, n, k, count, false)){
            return false;
        }
        else {
            arr.pop_back();
            count -= fib[n - arr.size() + 2];
            arr.push_back(false);
            if (gen(arr, n, k, count, false)){
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        arr.push_back(false);
        if(gen(arr, n, k, count, false)) {
            return true;
        }
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<bool> arr;
    gen(arr, n, k, 0, false);
}