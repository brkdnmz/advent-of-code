#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// this was fun, nice
// took quite a bit tho:D
// AC on the first attempt thanks to beatiful example cases
// felt like i overkilled

int main() {
    freopen("day12.txt", "r", stdin);
    vector<string> g;
    while (!cin.eof()) {
        string s;
        cin >> s;
        s = "$" + s + "$";
        g.push_back(s);
    }
    string tmp(g[0].size(), '$');
    g.insert(g.begin(), tmp);
    g.push_back(tmp);
    int n = g.size() - 2, m = g[0].size() - 2;
    bool vis[n + 2][m + 2] = {};
    ll ans = 0;
    int dx[] = {-1, 0, 1, -0}, dy[] = {0, -1, 0, 1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
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
                for (int dx : {-1, 1}) {
                    for (int dy : {-1, 1}) {
                        int nx = x + dx, ny = y + dy;
                        int cnt = 0;
                        cnt += g[x][ny] == g[x][y];
                        cnt += g[nx][y] == g[x][y];
                        perimeter += !cnt || (g[nx][ny] != g[x][y] && cnt == 2);
                    }
                }
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx > n || ny > m || vis[nx][ny])
                        continue;
                    if (g[x][y] != g[nx][ny])
                        continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            // cout << area << " " << perimeter << "\n";
            ans += (ll)area * perimeter;
        }
    }
    cout << ans << "\n";
}