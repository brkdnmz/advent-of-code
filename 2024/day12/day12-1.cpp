#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day12.txt", "r", stdin);
    vector<string> g;
    while (!cin.eof()) {
        string s;
        cin >> s;
        g.push_back(s);
    }
    int n = g.size(), m = g[0].size();
    bool vis[n][m] = {};
    ll ans = 0;
    int dx[] = {-1, 0, 1, -0}, dy[] = {0, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j])
                continue;
            queue<array<int, 2>> q;
            q.push({i, j});
            vis[i][j] = 1;
            int area = 0, perimeter = 0;
            while (q.size()) {
                area++;
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    perimeter += nx < 0 || ny < 0 || nx == n || ny == m || g[x][y] != g[nx][ny];
                    if (nx < 0 || ny < 0 || nx == n || ny == m || vis[nx][ny])
                        continue;
                    if (g[x][y] != g[nx][ny])
                        continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            ans += (ll)area * perimeter;
        }
    }
    cout << ans << "\n";
}