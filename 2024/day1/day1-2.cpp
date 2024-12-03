#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("day1.txt", "r", stdin);
    vector<int> l;
    unordered_map<int, int> cnt;
    while (!cin.eof()) {
        int x, y;
        cin >> x >> y;
        l.push_back(x);
        cnt[y]++;
    }
    ll ans = 0;
    for (int i = 0; i < l.size(); i++) {
        ans += 1ll * l[i] * cnt[l[i]];
    }
    cout << ans << "\n";
}