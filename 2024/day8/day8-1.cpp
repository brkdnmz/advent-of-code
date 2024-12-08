#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("day8.txt", "r", stdin);

    vector<string> g;
    while (!cin.eof()) {
        string s;
        cin >> s;
        g.push_back(s);
    }

    int n = g.size(), m = g[0].size();

    unordered_map<char, vector<array<int, 2>>> locs;

    bool antinode[n][m] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') // Forgot this in the first attempt, got 2500 :D
                continue;
            for (auto &[x, y] : locs[g[i][j]]) {
                int ni = 2 * i - x, nj = 2 * j - y;
                if (ni >= 0 && nj >= 0 && ni < n && nj < m)
                    antinode[ni][nj] = 1;
                ni = 2 * x - i, nj = 2 * y - j;
                if (ni >= 0 && nj >= 0 && ni < n && nj < m)
                    antinode[ni][nj] = 1;
            }

            locs[g[i][j]].push_back({i, j});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += antinode[i][j];
        }
    }

    cout << ans << "\n";
}