#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ~5 attempts on this one, SO BAD xd
// discovered the system has a cooldown of 5 mins

int main() {
    freopen("day9.txt", "r", stdin);

    string s;
    cin >> s;

    bool is_block = true;
    int pos = 0;
    ll checksum = 0;
    vector<array<int, 2>> free_spaces, blocks;

    auto gauss = [&](ll block_id, ll l, ll len) {
        return block_id * ((l + len - 1) * (l + len) / 2 - (l - 1) * l / 2);
    };

    for (char c : s) {
        c -= '0';
        if (is_block) {
            blocks.push_back({pos, c});
            checksum += gauss(blocks.size() - 1, pos, c);
        } else {
            free_spaces.push_back({pos, c});
        }
        is_block ^= 1;
        pos += c;
    }

    int r = blocks.size() - 1;

    for (int i = 0; i < free_spaces.size() - is_block && i < r; i++) {
        while (i < r && free_spaces[i][1] >= blocks[r][1]) {
            checksum -= gauss(r, blocks[r][0], blocks[r][1]);
            checksum += gauss(r, free_spaces[i][0], blocks[r][1]);
            free_spaces[i][0] += blocks[r][1];
            free_spaces[i][1] -= blocks[r--][1];
        }

        if (i >= r)
            break;

        checksum -= gauss(r, blocks[r][0] + blocks[r][1] - free_spaces[i][1], free_spaces[i][1]);
        checksum += gauss(r, free_spaces[i][0], free_spaces[i][1]);
        blocks[r][1] -= free_spaces[i][1];
    }
    cout << checksum << "\n";
}