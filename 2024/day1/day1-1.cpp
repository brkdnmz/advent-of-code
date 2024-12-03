#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("day1.txt", "r", stdin);
    vector<int> l, r;
    while (!cin.eof()) {
        int x, y;
        cin >> x >> y;
        l.push_back(x);
        r.push_back(y);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int ans = 0;
    for (int i = 0; i < l.size(); i++)
        ans += abs(r[i] - l[i]);
    cout << ans << "\n";
}