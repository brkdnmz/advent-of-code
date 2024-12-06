#include <bits/stdc++.h>
using namespace std;

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
    int d = 0;
    bool vis[n][m] = {};
    while (1) {
        auto [i, j] = cur;
        vis[i][j] = 1;
        int ni = i + dx[d], nj = j + dy[d];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m)
            break;
        (d += g[ni][nj] == '#') %= 4;
        ni = i + dx[d], nj = j + dy[d];
        cur = {ni, nj};
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += vis[i][j];
        }
    }
    cout << ans << "\n";
}