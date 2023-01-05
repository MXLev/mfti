//
// Created by Lev Skuratov on 20.08.2022.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=967e972a5964541a&action=139&prob_id=1

#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int main(){
    string flag;
    cin >> flag;
    if (flag == "encode"){
        string s;
        cin >> s;
        string coder = "informatcs";
        for (char i : s) {
            cout << (coder.find(i)) + 1;
        }
    } else if (flag == "decode"){
        ll n;
        cin >> n;
        ll t;
        cin >> t;
        string s = to_string(t);
        string coder = "informatcs";
        for (int i = 0; i < n; ++i) {
            if (i != s.size() - 1 && s[i] == '1' && s[i + 1] == '0'){
                cout << coder[9];i++;
            } else {
                cout << coder[s[i] - 49];
            }
        }
    }
    cout.flush();
}