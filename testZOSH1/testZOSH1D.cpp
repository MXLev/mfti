//
// Created by Beast on 13.11.2022.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=c1642bf19ac4f8d9&action=139&prob_id=4

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> stack;
    vector<int> maxStack;
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        string input = "";
        cin >> input;

        if (input == "max"){
            cout << *maxStack.rbegin() << '\n';
        } else if (input == "pop"){
            stack.pop_back();
            maxStack.pop_back();
        } else {
            int v;
            cin >> v;
            if (!maxStack.empty()){
                maxStack.push_back(max(*maxStack.rbegin(), v));
            } else {
                maxStack.push_back(v);
            }
            stack.push_back(v);
        }
    }
}