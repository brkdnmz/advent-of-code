#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        unordered_set<int> seen;
        vector<int> last_4;
        for (int t = 0; t < n; t++) {
            x = prune(x ^= x << 6);
            x = prune(x ^= x >> 5);
            x = prune(x ^= x << 11);

            int cur = x % 10;

            int diff = cur - prev;
            prev = cur; //
            diff += 9;  // offset
            last_4.push_back(diff);

            if (t >= 3) {
                int hsh = last_4[0] + last_4[1] * 19 + last_4[2] * 19 * 19 + last_4[3] * 19 * 19 * 19;
                last_4.erase(last_4.begin());
                if (seen.count(hsh)) {
                    continue;
                }
                seen.insert(hsh);
                dp[hsh] += cur;
            }

            // this line was there before, shit:
            // prev = cur;
            // the above "continue" messed things up xd
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}