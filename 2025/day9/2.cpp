#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// this solution will (should) fail sometimes when there are two parallel edges with no gap between

// i can't believe my eyes, this actually worked

// im so happyyyyy

// i checked reddit and realized that the input is actually a circle, but decided to write a generalized solution anyway

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
        corners.push_back({x, y});
    }
    int n = corners.size();
    auto check = [&](ll minx, ll miny, ll maxx, ll maxy) {
        for (int i = 0; i < n; i++) {
            auto [x1, y1] = corners[i];
            auto [x2, y2] = corners[(i + 1) % n];
            // vertical
            if (x1 == x2) {
                if (minx < x1 && x1 < maxx && !(min(y1, y2) >= maxy || max(y1, y2) <= miny))
                    return false;
            } else { // horizontal
                if (miny < y1 && y1 < maxy && !(min(x1, x2) >= maxx || max(x1, x2) <= minx))
                    return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        auto [cx, cy] = corners[i];
        for (int j = i + 1; j < n; j++) {
            auto [ox, oy] = corners[j];
            ll minx = min(cx, ox), miny = min(cy, oy), maxx = max(cx, ox), maxy = max(cy, oy);
            // does any edge passes through this rectangle?
            // (each edge is a wall between outside and inside)
            if (check(minx, miny, maxx, maxy)) {
                ans = max(ans, ((abs(cx - ox) + 1) * (abs(cy - oy) + 1)));
            }
        }
    }
    cout << ans << "\n";
}