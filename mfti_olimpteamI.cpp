//
// Created by Lev Skuratov on 25.08.2022.
// https://official.contest.yandex.ru/contest/39555/problems/I/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dfs(int v, int &c, vector<int> &used, vector<vector<int>> &arr)
{
    for (int u : arr[v])
    {
        if (used[u] == -1)
        {
            dfs(u, c, used, arr);
            used[u] = c;
        }
    }
}

int main(){
    int a;
    cin>>a;
    string b;
    vector<int> used(a,-1);
    vector<vector<int>> arr(a);
    for(int i=0;i<a;i++){
        cin>>b;
        for(int c=0;c<a;c++){
            if(b[c]=='1'){
                arr[i].push_back(c);
            }
        }
    }
    int c = 0;
    for (int i = 0; i < a; ++i)
    {
        if (used[i] == -1)
            dfs(i, c, used, arr);
        used[i] = c;
    }
    cout << c;
}