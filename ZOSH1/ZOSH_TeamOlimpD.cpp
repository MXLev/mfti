#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class num {
public:
    int index, value;
};

bool comparator(num first, num second){
    return first.value < second.value;
}

int main() {
    fastio();
    int n, s;
    cin >> n >> s;

    vector<num> potions(n);
    for (int i = 0; i < n; ++i) {
        cin >> potions[i].value;
        potions[i].index = i;
    }

    sort(potions.begin(), potions.end(), comparator);
    for (num i : potions)
        cout << i.value << ' ';
    cout << '\n';
    for (num i : potions)
        cout << i.index << ' ';
    cout << '\n';
    return 0;
}