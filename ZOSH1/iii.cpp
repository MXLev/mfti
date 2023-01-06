//
// Created by Lev Skuratov on 04.01.2023.
//

//#include <iostream>
//#include <vector>
//#include <set>
//#include <map>
//#include <cmath>

#include <bits/stdc++.h>

using namespace std;

void berw(int *a){
    auto charly = &a;
    pair<int, int> p;//p.first; p.second
    set<int> s;
    //s.insert();
    map<int, int> dict;
    //dict[key] = value
}

int main() {
    int a = 0;
    //int 2*10^9
    //long long 10^18
    // double
    // ++i i++ = i += 1
    cin >> a;
    cout << a << ' ' << 0;//"" ''
    for (int i = 0; i < a ; ++i){

    }
    //int b[arr];
    //int c[] = {1, 2, 3, 4};
    vector<int> arr;
    arr.push_back(a);
    arr.pop_back();
    arr.assign(a, 10);
    arr.resize(a);
    arr[0] = 0;
    auto e = arr.begin();//rbegin(), end(), rend()
    if (find(arr.begin(), arr.end(), a) != arr.end()){//(and = &&, or = ||, not = !, elif = else if())
        return 0;
    } else if (count(arr.begin(), arr.end(), a) == 0){
        return 1;
    }

    sort(arr.begin(), arr.end());
    //(arr, b) = (b, arr) == swap(arr, b)
    //arr**b == pow(arr, b)
    max_element(arr.begin(), arr.end());

    double qwer = 0;
    ceil(qwer);
    floor(qwer);
    floor(qwer + 0.5);
    round(qwer);
}
