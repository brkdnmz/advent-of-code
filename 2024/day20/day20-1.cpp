#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// lots of lots of mistakes led to 35 mins...

int main() {
    freopen("day20.txt", "r", stdin);
    vector<string> g;
    while (!cin.eof()) {
        string s;
        cin >> s;
        g.push_back(s);
    }
    int n = g.size(), m = g[0].size();
    array<int, 2> s, e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S')
                s = {i, j};
            if (g[i][j] == 'E')
                e = {i, j};
        }
    }
    auto cur = s;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[s[0]][s[1]] = 0;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    int limit = 100;
    int ans = 0;
    while (1) {
        auto [x, y] = cur;
        set<array<int, 2>> st;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            for (int dd = 0; dd < 4; dd++) {
                int nnx = nx + dx[d], nny = ny + dy[d];
                if (nnx >= 0 && nnx < n && nny >= 0 && nny < m && dist[nnx][nny] + limit + 2 <= dist[x][y]) {
                    st.insert({nnx, nny});
                }
            }
        }
        ans += st.size();
        if (cur == e)
            break;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (dist[nx][ny] == 1e9 && (g[nx][ny] == '.' || g[nx][ny] == 'E')) {
                dist[nx][ny] = dist[x][y] + 1;
                x = nx, y = ny;
                break;
            }
        }
        cur = {x, y};
    }
    cout << ans << "\n";
}