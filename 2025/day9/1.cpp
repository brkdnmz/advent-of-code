#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    vector<array<ll, 2>> corners;
    ll ans = 0;
    while (getline(cin, s)) {
        regex rgx("(\\d*),(\\d*)");
        smatch matches;
        regex_search(s, matches, rgx);
        ll x = stoll(matches[1].str()), y = stoll(matches[2].str());
        for (auto [xx, yy] : corners)
            ans = max(ans, (abs(x - xx) + 1) * (abs(y - yy) + 1));
        corners.push_back({x, y});
    }

    cout << ans << "\n";
}