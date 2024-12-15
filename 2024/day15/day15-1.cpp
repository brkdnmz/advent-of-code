#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day15.txt", "r", stdin);
    vector<string> grid;
    bool init = false;
    int x, y;
    int n, m;
    while (!cin.eof()) {
        string s;
        cin >> s;
        if (s[0] == '#') {
            string ns;
            for (char c : s) {
                if (c == '#' || c == '.')
                    ns += string(2, c);
                else if (c == 'O')
                    ns += "[]";
                else
                    ns += "@.";
            }
            grid.push_back(s);
        } else {
            if (!init) {
                n = grid.size(), m = grid[0].size();
                for (int i = 1; i < n; i++) {
                    for (int j = 2; j < m - 1; j++) {
                        if (grid[i][j] == '@')
                            x = i, y = j;
                    }
                }
                init = 1;
            }

            int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
            int d;
            for (char c : s) {
                switch (c) { // i'd written 'c' here wtf
                case '<':
                    d = 1;
                    break;
                case '^':
                    d = 0;
                    break;
                case '>':
                    d = 3;
                    break;
                case 'v':
                    d = 2;
                    break;
                }
                int nx = x + dx[d], ny = y + dy[d];
                if (grid[nx][ny] == '.') {
                    swap(grid[x][y], grid[nx][ny]);
                    x = nx, y = ny;
                } else if (grid[nx][ny] == '#')
                    continue;
                else {
                    int dist = 0;
                    while (grid[nx + dx[d] * dist][ny + dy[d] * dist] == 'O')
                        dist++;
                    if (grid[nx + dx[d] * dist][ny + dy[d] * dist] == '.') {
                        swap(grid[nx + dx[d] * dist][ny + dy[d] * dist], grid[nx][ny]);
                        swap(grid[x][y], grid[nx][ny]);
                        x = nx, y = ny;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            ans += (grid[i][j] == 'O') * (100 * i + j);
        }
    }
    cout << ans << "\n";
}