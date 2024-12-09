#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// I had solved this using set, but have converted to deque afterward...
// ...is what I would say IF could solve with deque :Dd
// couldn't... :'(

int main() {
    freopen("day9.txt", "r", stdin);

    string s;
    cin >> s;

    bool is_block = true;
    int pos = 0;
    ll checksum = 0;
    vector<array<int, 2>> blocks;
    set<int> free_spaces[10];

    auto gauss = [&](ll block_id, ll l, ll len) {
        return block_id * ((l + len - 1) * (l + len) / 2 - (l - 1) * l / 2);
    };

    for (char c : s) {
        c -= '0';
        if (is_block) {
            blocks.push_back({pos, c});
            checksum += gauss(blocks.size() - 1, pos, c);
        } else {
            free_spaces[c].insert(pos);
        }
        is_block ^= 1;
        pos += c;
    }

    for (int i = blocks.size() - 1; i >= 0; i--) {
        auto [pos, sz] = blocks[i];
        array<int, 2> lmost = {(int)1e9, (int)1e9};
        for (int j = sz; j < 10; j++) {
            if (free_spaces[j].size() && *free_spaces[j].begin() < lmost[0])
                lmost = {*free_spaces[j].begin(), j};
        }
        if (lmost[0] >= pos)
            continue;
        // cout << i << " " << lmost[0] << "\n";
        checksum -= gauss(i, pos, sz);
        checksum += gauss(i, lmost[0], sz);
        auto [fpos, fsz] = lmost;
        free_spaces[fsz].erase(free_spaces[fsz].begin());
        fsz -= sz;
        free_spaces[fsz].insert(fpos + sz);
    }

    cout << checksum << "\n";
}