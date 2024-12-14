#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day14-modified.txt", "r", stdin);
    int n = 103, m = 101;
    int t = 100;
    int cnt[2][2] = {};
    while (!cin.eof()) {
        int x, y, vx, vy;
        cin >> y >> x >> vy >> vx; // read these in reverse order in the 1st attempt...
        for (int i = 0; i < t; i++) {
            (x += vx + n) %= n;
            (y += vy + m) %= m;
        }
        if (x == n / 2 || y == m / 2)
            continue;
        cnt[x < n / 2][y < m / 2]++;
    }
    ll ans = 1;
    for (int i : {0, 1})
        for (int j : {0, 1})
            ans *= cnt[i][j];
    cout << ans << "\n";
}