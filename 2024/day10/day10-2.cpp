#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ok lets flex for this one with dp

int main() {
    freopen("day10.txt", "r", stdin);
    vector<string> g;
    while (!cin.eof()) {
        string s;
        cin >> s;
        for (char &c : s)
            c -= '0';
        g.push_back(s);
    }
    int n = g.size(), m = g[0].size();
    ll dp[n][m] = {};
    int in[n][m] = {};
    bool vis[n][m] = {};
    queue<array<int, 2>> q;
    int dx[] = {-1, 0, 1, -0}, dy[] = {0, -1, 0, 1};
    auto safe = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };

    // this can be further optimized with multisource bfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j])
                continue;
            queue<array<int, 2>> q;
            q.push({i, j});
            vis[i][j] = 1;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (!safe(nx, ny) || g[nx][ny] - g[x][y] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!g[i][j])
                q.push({i, j}), dp[i][j] = 1;
            else {
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    in[i][j] += safe(nx, ny) && vis[nx][ny] && g[nx][ny] + 1 == g[i][j];
                }
            }
        }
    }
    ll ans = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!safe(nx, ny) || g[nx][ny] != g[x][y] + 1)
                continue;
            dp[nx][ny] += dp[x][y];
            if (!--in[nx][ny]) {
                q.push({nx, ny});
                ans += (g[nx][ny] == 9) * dp[nx][ny];
            }
        }
    }
    cout << ans << "\n";
}