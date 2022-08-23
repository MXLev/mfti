//
// Created by Lev Skuratov on 22.08.2022.
// https://official.contest.yandex.ru/contest/39328/problems/B6/

#include <bits/stdc++.h>


using namespace std;

int main(){
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        vector<bool> arr;
        int a;
        cin >> a;
        int last = arr[arr.size() - 1];
        if (a > 0){
            for (int i = 0; i < arr.size(); ++i) {
                if (i < arr.size() && arr[i]){
                    arr[i] = true;
                    break;
                } else if (i >= arr.size()){
                    arr.resize(i + 1);
                    arr[i] = true;
                    break;
                }
            }
        } else {
        }
    }
}