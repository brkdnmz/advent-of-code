#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    bool querying = false;
    bool preprocessed = false;
    map<ll, int> cnt;
    ll ans = 0;
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
                ll l = 0;
                for (auto &[k, v] : cnt) {
                    int prev = acc;
                    v = acc += v;
                    if (!v) {
                        ans += k - l;
                    }
                    if (!prev)
                        l = k;
                }
                preprocessed = 1;
            }
        }
    }
    cout << ans << "\n";
}