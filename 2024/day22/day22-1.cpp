#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day22.txt", "r", stdin);
    ll ans = 0;
    auto prune = [&](ll x) { return x % 16777216; };
    while (!cin.eof()) {
        ll x;
        cin >> x;
        int n = 2000;
        while (n--) {
            x = prune(x ^= x << 6);
            x = prune(x ^= x >> 5);
            x = prune(x ^= x << 11);
        }
        ans += x;
    }
    cout << ans << "\n";
}