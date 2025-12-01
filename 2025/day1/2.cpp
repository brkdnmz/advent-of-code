#include <bits/stdc++.h>
using namespace std;

// feels like i overcomplicated
int main() {
    freopen("1.txt", "r", stdin);
    int cur = 50;
    int ans = 0;
    while (!cin.eof()) {
        string s;
        cin >> s;
        int dir = 1 - 2 * (s[0] == 'L');
        int dist = stoi(s.substr(1));
        int prev = cur;
        cur += dist * dir;
        int a = abs(prev), b = abs(cur);
        if (a < b)
            swap(a, b);
        // number of multiples of 100 between prev and cur
        if ((prev < 0) == (cur > 0))
            ans += a / 100 + b / 100 + 1;
        else
            ans += (a + 100) / 100 - (b - 1 + 100) / 100;
        ans -= prev % 100 == 0;
        // cout << prev << " " << cur << " " << ans << "\n";
    }

    cout << ans << "\n";
}