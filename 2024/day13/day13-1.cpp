#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day13-modified.txt", "r", stdin);
    int ans = 0;
    while (!cin.eof()) {
        int ax, ay, bx, by, px, py;
        cin >> ax >> ay >> bx >> by >> px >> py;
        int mn = 1e9;
        for (int a = 0; a <= 100; a++) {
            for (int b = 0; b <= 100; b++) {
                if (a * ax + b * bx == px && a * ay + b * by == py) {
                    mn = min(mn, 3 * a + b);
                }
            }
        }
        if (mn < 1e9)
            ans += mn;
    }
    cout << ans << "\n";
}