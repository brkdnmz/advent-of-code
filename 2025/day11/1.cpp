#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    ll ans = 0;
    map<string, vector<string>> g;
    while (getline(cin, s)) {
        regex rgx("^(\\w+):");
        smatch matches;
        regex_search(s, matches, rgx);
        string u = matches[1];
        rgx = "(\\w+)";
        for (auto it = sregex_iterator(s.begin(), s.end(), rgx); it != sregex_iterator(); it++) {
            g[u].push_back((*it)[1]);
        }
    }

    set<string> vis;
    map<string, ll> dp;
    auto dfs = [&](auto &&self, string u) {
        if (u == "out")
            return 1ll;
        vis.insert(u);
        ll ways = 0;
        for (string x : g[u]) {
            if (vis.count(x)) {
                ways += dp[x];
                continue;
            }
            ways += self(self, x);
        }
        return dp[u] = ways;
    };

    cout << dfs(dfs, "you") << "\n";
}