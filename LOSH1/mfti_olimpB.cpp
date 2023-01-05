//
// Created by Lev Skuratov on 20.08.2022.
// http://ioi-russia.vdi.mipt.ru/~ejudge/team.cgi?SID=967e972a5964541a&action=139&prob_id=3

#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int main(){
   ll q;
   cin >> q;
   cout << "? " << 0 << ' ' << 0 << '\n';
   cout.flush();
   ll answ = 0;
   cin >> answ;
   while (answ != 0){
       cout << "? " << answ << ' ' << answ;
       cout.flush();
       cin >> answ;
   }
   cout << "! " << answ << '\n';
}