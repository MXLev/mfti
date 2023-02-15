    #include <bits/stdc++.h>
    using namespace std;
    inline int is_in(const int& x1, const int& y1){
        if(x1 > 0 && y1 > 0){
            return 2;
        }
        else if(x1 < 0 && y1 > 0){
            return 1;
        }
        else if(x1 < 0 && y1 < 0){
            return 3;
        }
        else if(x1 > 0 && y1 < 0){
            return 4;
        }
        else if(x1 == 0 && y1 > 0){
            return 2;
        }

        else if(x1 == 0 && y1 < 0){
            return 1;
        }

        else if(y1 == 0 && x1 > 0){
            return 2;
        }

        else if(y1 == 0 && x1 < 0){
            return 1;
        }
    }
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0) || (x3 == 0 && y3 == 0)) {
            cout << 987654321 << '\n';
            return 0;
        }
        if(x1 == 0 && x2 == 0 && ((y1 > 0 && y2 < 0) || (y2 > 0 && y1 < 0))){
            cout << 987654321 << '\n';
            return 0;
        }

        if(x1 == 0 && x3 == 0 && ((y1 > 0 && y3 < 0) || (y3 > 0 && y1 < 0))){
            cout << 987654321 << '\n';
            return 0;
        }

        if(x2 == 0 && x3 == 0 && ((y2 > 0 && y3 < 0) || (y3 > 0 && y2 < 0))){
            cout << 987654321 << '\n';
            return 0;
        }

        if(y1 == 0 && y2 == 0 && ((x1 > 0 && x2 < 0) || (x2 > 0 && x1 < 0))){
            cout << 987654321 << '\n';
            return 0;
        }
        if(y1 == 0 && y3 == 0 && ((x1 > 0 && x3 < 0) || (x3 > 0 && x1 < 0))){
            cout << 987654321 << '\n';
            return 0;
        }

        if(y2 == 0 && y3 == 0 && ((x2 > 0 && x3 < 0) || (x3 > 0 && x2 < 0))){
            cout << 987654321 << '\n';
            return 0;
        }
        if(is_in(x1, y1)  != is_in(x2, y2) && is_in(x3, y3) != is_in(x1, y1)){
            cout << 987654321 << '\n';
            return 0;
        }
        else {
            cout << -x1 << " " << -y1 << " " << -x2 << " " <<  -y2 << " " << -x3 << " " << -y3 <<      '\n';
        }
        return 0;
    }