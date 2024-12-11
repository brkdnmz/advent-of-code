#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int ans = 0;
    int dx[] = {-1, 0, 1, -0}, dy[] = {0, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // I had written j < n here but passed anyway
            if (g[i][j])
                continue;
            bool vis[n][m] = {};
            queue<array<int, 2>> q;
            q.push({i, j});
            vis[i][j] = 1;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx == n || ny == m || g[nx][ny] - g[x][y] != 1)
                        continue;
                    ans += g[nx][ny] == 9 && !vis[nx][ny];
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << ans << "\n";
}