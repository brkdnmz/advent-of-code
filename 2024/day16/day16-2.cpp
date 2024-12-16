#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// how many vectors u said????
// 5???
// thats ma first time actually
// (changed last one to array<int, 3> afterward)

int main() {
    freopen("day16.txt", "r", stdin);
    vector<string> grid;
    while (!cin.eof()) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    int n = grid.size(), m = grid[0].size();
    int sx, sy, ex, ey;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == 'S')
                sx = i, sy = j;
            if (grid[i][j] == 'E')
                ex = i, ey = j;
        }
    }
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    priority_queue<array<int, 4>> q;
    q.push({0, sx, sy, 3});
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, 1e9)));
    vector<vector<vector<vector<array<int, 3>>>>> p(
        n, vector<vector<vector<array<int, 3>>>>(m, vector<vector<array<int, 3>>>(4)));
    dist[sx][sy][3] = 0;
    while (q.size()) {
        auto [cost, i, j, dir] = q.top();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int turns = min(abs(d - dir), 4 - abs(d - dir));
            if (dist[i][j][d] > dist[i][j][dir] + 1000 * turns) {
                dist[i][j][d] = dist[i][j][dir] + 1000 * turns;
                p[i][j][d] = {{i, j, dir}};
                q.push({-dist[i][j][d], i, j, d});
            } else if (dist[i][j][d] == dist[i][j][dir] + 1000 * turns)
                p[i][j][d].push_back({i, j, dir});
        }
        int ni = i + dx[dir], nj = j + dy[dir];
        if (grid[ni][nj] == '#')
            continue;
        if (dist[ni][nj][dir] > dist[i][j][dir] + 1) {
            dist[ni][nj][dir] = dist[i][j][dir] + 1;
            p[ni][nj][dir] = {{i, j, dir}};
            q.push({-dist[ni][nj][dir], ni, nj, dir});
        } else if (dist[ni][nj][dir] == dist[i][j][dir] + 1) {
            p[ni][nj][dir].push_back({i, j, dir});
        }
    }
    int min_score = *min_element(dist[ex][ey].begin(), dist[ex][ey].end());
    bool vis[n][m][4] = {};
    queue<array<int, 3>> qq;
    for (int d = 0; d < 4; d++)
        if (dist[ex][ey][d] == min_score)
            qq.push({ex, ey, d});
    while (qq.size()) {
        auto [i, j, d] = qq.front();
        qq.pop();
        if (vis[i][j][d])
            continue;
        vis[i][j][d] = 1;
        for (auto x : p[i][j][d])
            qq.push(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool ok = 0;
            for (int d = 0; d < 4; d++)
                ok |= vis[i][j][d];
            ans += ok;
        }
    }
    cout << ans << "\n";
}