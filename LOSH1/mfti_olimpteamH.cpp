//
// Created by Lev Skuratov on 25.08.2022.
//https://official.contest.yandex.ru/contest/39555/problems/H/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string a,b,c="";
    cin>>a;

    int h,m;
    for(int i=0;i<a.size();i++) {
        if (a[i] == '-' || a[i] == '+'){
            while (a[i]!='x'&&i<a.size()){
                b+=a[i];
                i++;
            }
            h=stoi(b);
            i+=2;
            if(i!=a.size()){
                b="";
                while(a[i]!='-'||a[i]!='+'){
                    b+=a[i];
                }
                m=stoi(b);
                if(m-1>0)
                cout<<m*h<<"x^"<<m-1;
                if(m-1==0)
                    cout<<h;
                if(m-1==-1)
                    cout<<0;
            }
        }


    }
}