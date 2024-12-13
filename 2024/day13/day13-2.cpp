#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// wow this took 4 attempts with many silly mistakes

int main() {
    freopen("day13-modified.txt", "r", stdin);
    ll ans = 0;
    ll offset = 10000000000000;
    while (!cin.eof()) {
        ll ax, ay, bx, by, px, py;
        cin >> ax >> ay >> bx >> by >> px >> py;
        px += offset, py += offset;
        ll mn = 1e18;
        // a*ax + b*bx == px
        // a*ay + b*by == py
        if (ax * by == ay * bx && ax * py == ay * px) { // this didnt appear lol
            for (int a = 0; a <= 100; a++) {
                ll x = px - a * ax;
                if (x >= 0 && x % bx == 0) {
                    mn = min(mn, 3 * a + x / bx);
                }
            }
            for (int b = 0; b <= 100; b++) {
                ll x = px - b * bx;
                if (x >= 0 && x % ax == 0) {
                    mn = min(mn, b + 3 * (x / ax));
                }
            }
        } else if (by * ax != bx * ay) {
            /*
                a = (px - b*bx)/ax = (py - b*by)/ay
                px*ay - b*bx*ay = ax*py - b*by*ax
                b(by*ax - bx*ay) = ax*py - px*ay
            */
            if ((ax * py - px * ay) % (by * ax - bx * ay))
                continue;
            ll b = (ax * py - px * ay) / (by * ax - bx * ay);
            ll a = (px - b * bx) / ax;
            if ((px - b * bx) % ax)
                continue;
            assert(px * ay - b * bx * ay == ax * py - b * by * ax);
            // assert(a * ax + b * bx == px);
            // assert(a * ay + b * by == py);
            if (a >= 0 && b >= 0) {
                mn = 3 * a + b;
            }
        }
        if (mn < 1e18)
            ans += mn;
    }
    cout << ans << "\n";
}