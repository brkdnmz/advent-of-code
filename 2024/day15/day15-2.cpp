#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// wow this took TOOOOOOOOO long
// but got in on the 1st attempt

vector<string> grid;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
bool can_move_mem[100][100];
bool can_move(int i, int j, int d) {
    auto &cur = can_move_mem[i][j];
    if (grid[i][j] == '.' || grid[i][j] == '#')
        return cur = grid[i][j] == '.';
    if (grid[i][j] == '@')
        return cur = can_move(i + dx[d], j + dy[d], d);
    if (grid[i][j] == '[') {
        return cur = d == 1   ? can_move(i + dx[d], j + dy[d], d)
                     : d == 3 ? can_move(i, j + 1, d)
                              : can_move(i + dx[d], j + dy[d], d) && can_move(i + dx[d], j + dy[d] + 1, d);
    }
    if (grid[i][j] == ']') {
        return cur = d == 1   ? can_move(i, j - 1, d)
                     : d == 3 ? can_move(i + dx[d], j + dy[d], d)
                              : can_move(i + dx[d], j + dy[d], d) && can_move(i + dx[d], j + dy[d] - 1, d);
    }
    return false; // can't come here
}
void move(int i, int j, int d) {
    if (!can_move_mem[i][j])
        return;
    if (grid[i][j] == '.' || grid[i][j] == '#')
        return;
    if (grid[i][j] == '@') {
        move(i + dx[d], j + dy[d], d);
        swap(grid[i][j], grid[i + dx[d]][j + dy[d]]);
        return;
    }
    if (grid[i][j] == '[') {
        move(i + dx[d], j + dy[d], d);
        if (!(d % 2))
            move(i + dx[d], j + dy[d] + 1, d);
        grid[i][j] = grid[i][j + 1] = '.';
        grid[i + dx[d]][j + dy[d]] = '[';
        grid[i + dx[d]][j + dy[d] + 1] = ']';
        return;
    }
    if (grid[i][j] == ']') {
        move(i + dx[d], j + dy[d], d);
        if (!(d % 2))
            move(i + dx[d], j + dy[d] - 1, d);
        grid[i][j] = grid[i][j - 1] = '.';
        grid[i + dx[d]][j + dy[d] - 1] = '[';
        grid[i + dx[d]][j + dy[d]] = ']';
    }
}

int main() {
    freopen("day15.txt", "r", stdin);
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
            grid.push_back(ns);
        } else {
            if (!init) {
                n = grid.size(), m = grid[0].size();
                for (int i = 1; i < n; i++) {
                    for (int j = 2; j < m; j++) {
                        if (grid[i][j] == '@')
                            x = i, y = j;
                    }
                }
                init = 1;
            }

            int d;
            for (char c : s) {
                switch (c) {
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
                    can_move(x, y, d);
                    move(x, y, d);
                    if (can_move_mem[x][y])
                        x = nx, y = ny;
                    memset(can_move_mem, 0, sizeof(can_move_mem));
                }
            }
        }
    }
    // for (string &s : grid)
    //     cout << s << endl;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            ans += (grid[i][j] == '[') * (100 * i + j);
        }
    }
    cout << ans << "\n";
}