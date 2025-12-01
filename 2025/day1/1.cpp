#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("1.txt", "r", stdin);
    int cur = 50;
    int ans = 0;
    while (!cin.eof()) {
        string s;
        cin >> s;
        int dir = 1 - 2 * (s[0] == 'L');
        int dist = stoi(s.substr(1));
        cur += 100 - dist * dir;
        cur %= 100;
        ans += !cur;
    }
    cout << ans << "\n";
}