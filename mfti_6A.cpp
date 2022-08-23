//
// Created by Lev Skuratov on 22.08.2022.
//https://official.contest.yandex.ru/contest/39328/problems/A6/

#include <bits/stdc++.h>


using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> s;
    for (int q = 0; q < n; ++q) {
        string input;
        int temp;
        cin >> input;
        string command;
        int i = 0;
        while (input[i] != '(' && i < input.size()){
            command += input[i];
            i++;
        }
        if (command == "Insert"){
            string t;
            i++;
            while (input[i] != ')'){
                t += input[i];
                ++i;
            }
            temp = stoi(t);
            s.insert(temp);
        } else if (command == "GetMin"){
            auto t = s.begin();
            cout << *t << '\n';
            s.erase(t);
        } else if (command == "GetMax"){
            auto t =  s.rbegin();
            cout << *t << '\n';
            s.erase(--s.end());
        }
    }
}