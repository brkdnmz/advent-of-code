#include <bits/stdc++.h>
using namespace std;

vector<string> g;
string target = "XMAS";

int main() {
    freopen("day4.txt", "r", stdin);
    while (!cin.eof()) {
        string s;
        cin >> s;
        g.push_back(s);
    }
    int ans = 0;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            for (int dx : {-1, 0, 1})
                for (int dy : {-1, 0, 1}) {
                    bool ok = true;
                    for (int k = 0; k < target.size() && ok; k++) {
                        int ni = i + dx * k, nj = j + dy * k;
                        ok &= ni >= 0 && ni < g.size() && nj >= 0 && nj < g[0].size() && g[ni][nj] == target[k];
                    }
                    ans += ok;
                }
        }
    }
    cout << ans << "\n";
}