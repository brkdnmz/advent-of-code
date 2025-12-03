#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 12;

int main() {
    freopen("1.txt", "r", stdin);
    ll tot = 0;
    while (!cin.eof()) {
        string s;
        cin >> s;
        for (char &c : s)
            c -= '0';
        int n = s.size();
        ll dp[M + 1][10] = {};
        for (int c : s) {
            for (int i = M; i; i--)
                for (int c2 = 0; c2 < 10; c2++)
                    dp[i][c] = max(dp[i][c], dp[i - 1][c2] * 10 + c);
            dp[1][c] = c;
        }
        tot += *max_element(dp[12], dp[12] + 10);
    }
    cout << tot << "\n";
}