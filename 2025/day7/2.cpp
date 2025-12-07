#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string prev;
    string s;
    vector<ll> dp;
    while (getline(cin, s)) {
        if (prev.empty()) {
            prev = s;
            dp.resize(s.size());
            dp[s.find('S')] = 1;
            continue;
        }
        vector<ll> ndp(dp.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '^') {
                // wrote = here, spent a lot before finding it out
                ndp[i] += dp[i];
            } else {
                if (i)
                    ndp[i - 1] += dp[i];
                if (i + 1 < s.size())
                    ndp[i + 1] += dp[i];
            }
        }
        dp = ndp;
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << "\n";
}