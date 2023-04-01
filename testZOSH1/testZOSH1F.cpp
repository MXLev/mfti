//
// Created by Beast on 13.11.2022.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=c1642bf19ac4f8d9&action=139&prob_id=5

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, string> index;
    index.insert({1, "i"});
    index.insert({2, "n"});
    index.insert({3, "f"});
    index.insert({4, "o"});
    index.insert({5, "r"});
    index.insert({6, "m"});
    index.insert({7, "a"});
    index.insert({8, "t"});
    index.insert({9, "c"});

    map<char, int> alphabet;
    alphabet.insert({'i', 1});
    alphabet.insert({'n', 2});
    alphabet.insert({'f', 3});
    alphabet.insert({'o', 4});
    alphabet.insert({'r', 5});
    alphabet.insert({'m', 6});
    alphabet.insert({'a', 7});
    alphabet.insert({'t', 8});
    alphabet.insert({'c', 9});
    alphabet.insert({'s', 10});

    string command;

    cin >> command;
    string input;

    if (command == "encode"){
        cin >> input;

        for (int i = 0; i < input.size(); ++i) {
            cout << alphabet[input[i]];
        }

        cout << '\n';
    } else if (command == "decode"){
        int n;
        cin >> n;
        cin >> input;

        for (int i = 0; i < input.size(); ++i) {
            if (i <= input.size() - 1 && input[i + 1] == '0' && n != input.size()){
                cout << "s";
                i++;
            } else {
                cout << index[input[i] - 48];
            }
        }
        cout << '\n';
    }
}