//
// Created by Beast on 13.11.2022.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=c1642bf19ac4f8d9&action=139&prob_id=3

#include <bits/stdc++.h>

using namespace std;

int main(){
    string input = "";
    getline(cin, input);

    //cout << input.size() << ", " << input[0] << ", " << input[1] << endl;

    string output = "";
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == ',' || input[i] == ';'){
            cout << '"' << output << '"' << '\n';
            output.erase();
        } else {
            output.push_back(input[i]);
        }
    }
    if (output.size() > 0) {
        cout << '"' << output << '"' << '\n';
    } else {
        cout << "\"\"" << "\n";
    }
}