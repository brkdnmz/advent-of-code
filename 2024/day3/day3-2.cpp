#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day3-2.txt", "r", stdin);
    ll ans = 0;
    bool enabled = true;
    while (!cin.eof()) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            enabled = x;
        } else {
            int x, y;
            cin >> x >> y;
            ans += x * y * enabled;
        }
    }
    cout << ans << "\n";
}