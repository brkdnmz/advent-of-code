#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    ll ans = 0;
    while (getline(cin, s)) {
        // capture #...##.., not capture the inner char
        regex rgx("\\[((?:#|.)*)\\]");
        smatch matches;
        regex_search(s, matches, rgx);
        string tar = matches[1];
        int n = tar.size();
        vector<int> dp(1 << n, 1e9);
        dp[0] = 0;
        int mask_req = 0;
        for (int i = 0; i < tar.size(); i++)
            mask_req |= (1 << i) * (tar[i] == '#');
        rgx = R"(\((\d+(?:,\d+)*)\))";
        for (auto it = sregex_iterator(s.begin(), s.end(), rgx); it != sregex_iterator(); it++) {
            istringstream ss((*it)[1]);
            string numstr;
            int mask = 0;
            while (getline(ss, numstr, ',')) {
                mask |= 1 << (stoi(numstr));
            }
            auto ndp = dp;
            for (int i = 0; i < (1 << n); i++)
                ndp[i ^ mask] = min(ndp[i ^ mask], dp[i] + 1);
            dp = ndp;
        }
        ans += dp[mask_req];
    }

    cout << ans << "\n";
}