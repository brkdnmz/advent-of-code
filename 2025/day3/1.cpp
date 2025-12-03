#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    ll tot = 0;
    while (!cin.eof()) {
        string s;
        cin >> s;
        for (char &c : s)
            c -= '0';
        int n = s.size();
        int mx = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                mx = max(mx, s[i] * 10 + s[j]);
        tot += mx;
    }
    cout << tot << "\n";
}