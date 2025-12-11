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
    auto dfs = [&](auto &&self, string u, string tar) {
        if (u == tar)
            return 1ll;
        vis.insert(u);
        ll ways = 0;
        for (string x : g[u]) {
            if (vis.count(x)) {
                ways += dp[x];
                continue;
            }
            ways += self(self, x, tar);
        }
        return dp[u] = ways;
    };

    ll svr_dac = dfs(dfs, "svr", "dac");
    vis.clear();
    dp.clear();
    ll svr_fft = dfs(dfs, "svr", "fft");
    vis.clear();
    dp.clear();
    ll dac_out = dfs(dfs, "dac", "out");
    vis.clear();
    dp.clear();
    ll fft_out = dfs(dfs, "fft", "out");
    vis.clear();
    dp.clear();
    ll dac_fft = dfs(dfs, "dac", "fft");
    vis.clear();
    dp.clear();
    ll fft_dac = dfs(dfs, "fft", "dac");
    // vis.clear();
    // dp.clear();
    // ll svr_out = dfs(dfs, "svr", "out");
    // cout << svr_out << "\n";
    cout << svr_dac * dac_fft * fft_out + svr_fft * fft_dac * dac_out << "\n";
}