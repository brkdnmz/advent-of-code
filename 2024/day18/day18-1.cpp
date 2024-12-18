#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 71;

int main() {
    freopen("day18-modified.txt", "r", stdin);
    vector<vector<bool>> g(N, vector<bool>(N));
    int cnt = 1024;
    while (cnt--) {
        int x, y;
        cin >> y >> x;
        g[x][y] = 1;
    }
    queue<array<int, 2>> q;
    vector<vector<int>> dist(N, vector<int>(N, 1e9));
    dist[0][0] = 0;
    q.push({0, 0});
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    auto safe = [&](int x, int y) { return x >= 0 && x < N && y >= 0 && y < N && !g[x][y]; };
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!safe(nx, ny) || dist[nx][ny] < 1e9)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[N - 1][N - 1] << "\n";
}