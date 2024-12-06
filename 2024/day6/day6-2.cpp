#include <bits/stdc++.h>
using namespace std;

// interesting problem imo, wonder how to optimize
// this works in n^2 * m^2

int main() {
    freopen("day6.txt", "r", stdin);
    vector<string> g;
    while (!cin.eof()) {
        string s;
        cin >> s;
        g.push_back(s);
    }

    int n = g.size(), m = g[0].size();

    // u, r, d, l
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    array<int, 2> cur;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '^')
                cur = {i, j};
        }
    }

    auto start = cur;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '.')
                continue;

            g[i][j] = '#';

            cur = start;
            bool ok = false;
            int d = 0;
            bool vis[n][m][4] = {};
            while (1) {
                auto [i, j] = cur;
                if (vis[i][j][d]) {
                    ok = true;
                    break;
                }
                vis[i][j][d] = 1;
                int ni = i + dx[d], nj = j + dy[d];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                    break;

                if (g[ni][nj] == '#') {
                    ++d %= 4;
                    continue;
                }

                ni = i + dx[d], nj = j + dy[d];
                cur = {ni, nj};
            }
            ans += ok;

            g[i][j] = '.';
        }
    }
    cout << ans << "\n";
}