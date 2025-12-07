#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    int ans = 0;
    string prev;
    string s;
    while (getline(cin, s)) {
        if (prev.empty()) {
            prev = s;
            continue;
        }
        for (int i = 0; i < s.size(); i++) {
            if (prev[i] != 'S')
                continue;
            if (s[i] != '^') {
                s[i] = prev[i];
                continue;
            }
            if (prev[i] != 'S')
                continue;
            ans++;
            if (i)
                s[i - 1] = 'S';
            if (i + 1 < s.size())
                s[i + 1] = 'S';
        }
        prev = s;
    }
    cout << ans << "\n";
}