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
    for (int i = 1; i + 1 < g.size(); i++) {
        for (int j = 1; j + 1 < g[0].size(); j++) {
            if (g[i][j] != 'A')
                continue;
            string t = {g[i - 1][j - 1], g[i - 1][j + 1], g[i + 1][j + 1], g[i + 1][j - 1]};
            ans += t == "MMSS" || t == "SMMS" || t == "SSMM" || t == "MSSM";
        }
    }
    cout << ans << "\n";
}