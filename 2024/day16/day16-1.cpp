#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// im so sleepless rn, awake 20 hrs

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
    dist[sx][sy][3] = 0;
    while (q.size()) {
        auto [cost, i, j, dir] = q.top();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int turns = min(abs(d - dir), 4 - abs(d - dir));
            if (dist[i][j][d] > dist[i][j][dir] + 1000 * turns) {
                dist[i][j][d] = dist[i][j][dir] + 1000 * turns;
                q.push({-dist[i][j][d], i, j, d});
            }
        }
        int ni = i + dx[dir], nj = j + dy[dir];
        if (grid[ni][nj] != '#' && dist[ni][nj][dir] > dist[i][j][dir] + 1) {
            dist[ni][nj][dir] = dist[i][j][dir] + 1;
            q.push({-dist[ni][nj][dir], ni, nj, dir});
        }
    }
    cout << *min_element(dist[ex][ey].begin(), dist[ex][ey].end()) << "\n";
}