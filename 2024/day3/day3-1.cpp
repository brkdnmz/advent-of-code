#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day3-1.txt", "r", stdin);
    ll ans = 0;
    while (!cin.eof()) {
        int x, y;
        cin >> x >> y;
        ans += x * y;
    }
    cout << ans << "\n";
}