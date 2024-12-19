#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day19-modified.txt", "r", stdin);
    string s;
    getline(cin, s);
    istringstream iss(s);
    vector<string> choices;
    string c;
    while (iss >> c) {
        choices.push_back(c);
    }
    int ans = 0;
    while (!cin.eof()) {
        string s;
        cin >> s;
        int n = s.size();
        bool dp[n + 1] = {};
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (string c : choices) {
                int m = c.size();
                if (m > i + 1)
                    continue;
                dp[i + 1] |= dp[i + 1 - m] && s.substr(i + 1 - m, m) == c;
            }
        }
        ans += dp[n];
    }
    cout << ans << "\n";
}