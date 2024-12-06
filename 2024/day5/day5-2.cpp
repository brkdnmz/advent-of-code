#include <bits/stdc++.h>
using namespace std;

vector<int> read_update() {
    string s;
    getline(cin, s);

    istringstream iss(s);

    vector<int> update;
    int x;
    while (iss >> x)
        update.push_back(x);
    return update;
}

int main() {
    freopen("day5.txt", "r", stdin);
    vector<vector<int>> before(100, vector<int>(100));
    int ans = 0;
    while (!cin.eof()) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            before[x][y] = 1;
        } else {
            auto update = read_update();
            bool ok = true;
            for (int i = 0; i < update.size(); i++) {
                for (int j = i + 1; j < update.size(); j++) {
                    if (before[update[j]][update[i]]) {
                        ok = false;
                        swap(update[j], update[i]);
                    }
                }
            }
            ans += !ok * update[update.size() / 2];
        }
    }
    cout << ans << "\n";
}