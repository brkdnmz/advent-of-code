#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// this solves buying at every non-overlapping occurrences of the diff pattern...

int main() {
    freopen("day22.txt", "r", stdin);
    // changes are from -9 to 9
    // 19^4 total changes
    int tot = 19 * 19 * 19 * 19;
    vector<int> dp(tot);
    int n = 2000;
    auto prune = [&](ll x) { return x % 16777216; };
    while (!cin.eof()) {
        ll x;
        cin >> x;
        int prev = x % 10;
        unordered_map<int, deque<array<int, 2>>> cur_dp;
        vector<int> last_4;
        for (int t = 0; t < n; t++) {
            x = prune(x ^= x << 6);
            x = prune(x ^= x >> 5);
            x = prune(x ^= x << 11);

            int cur = x % 10;

            int diff = cur - prev;
            diff += 9; // offset
            last_4.push_back(diff);

            if (t >= 3) {
                int hsh = last_4[0] + last_4[1] * 19 + last_4[2] * 19 * 19 + last_4[3] * 19 * 19 * 19;
                int mx = 0;
                for (int i = 0; i < cur_dp[hsh].size(); i++) {
                    auto [val, idx] = cur_dp[hsh].end()[-i - 1];
                    if (idx <= t - 4) {
                        mx = val;
                        break;
                    }
                    assert(i < 4);
                }
                dp[hsh] -= mx;
                dp[hsh] += mx + cur;
                cur_dp[hsh].push_back({mx + cur, t});
                last_4.erase(last_4.begin());
            }

            prev = cur;
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}