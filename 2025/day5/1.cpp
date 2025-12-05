#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    bool querying = false;
    bool preprocessed = false;
    map<ll, int> cnt;
    int ans = 0;
    while (getline(cin, s)) {
        if (!s.size()) {
            querying = 1;
            continue;
        }

        if (!querying) {
            int dashpos = s.find("-");
            ll l = stoll(s.substr(0, dashpos)), r = stoll(s.substr(dashpos + 1));
            if (l > r)
                swap(l, r);
            cnt[l]++;
            cnt[r + 1]--;
        } else {
            if (!preprocessed) {
                int acc = 0;
                for (auto &[k, v] : cnt) {
                    v = acc += v;
                }
                cnt[-1e18] = cnt[1e18] = 0;
                preprocessed = 1;
            }

            ll x = stoll(s);
            auto it = prev(cnt.lower_bound(x));
            if (cnt.count(x))
                ans += !!cnt[x];
            else {
                ans += !!it->second;
            }
        }
    }
    cout << ans << "\n";
}