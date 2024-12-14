#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ok i wonder how to generate test cases for this one
// (simulating backward should work imo, hm...)
// quite an interesting puzzle that i really had to figure out how to code
// took quite a while

int main() {
    auto f = freopen("day14-modified.txt", "r", stdin);
    int n = 103, m = 101;
    int t = 100;
    int cnt[2][2] = {};
    vector<array<int, 4>> robots;
    while (!cin.eof()) {
        int x, y, vx, vy;
        cin >> y >> x >> vy >> vx;
        robots.push_back({x, y, vx, vy});
    }
    for (int sec = 1;; sec++) {
        bool g[n][m] = {};
        for (auto &[x, y, vx, vy] : robots) {
            (x += vx + n) %= n;
            (y += vy + m) %= m;
            g[x][y] = 1;
        }
        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d = 0;
                for (; i + d < n && j - d >= 0 && j + d < m && g[i + d][j - d] && g[i + d][j + d]; d++) {
                }
                ok |= d >= 10;
            }
        }
        if (!ok)
            continue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (g[i][j] ? "#" : ".");
            }
            cout << "\n";
        }
        cout << sec << " seconds\n\n";
    }
}