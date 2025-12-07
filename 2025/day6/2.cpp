#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// oh boy this was a bit dirty

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    vector<string> ints;
    ll ans = 0;
    while (getline(cin, s)) {
        if (regex_search(s, regex("\\d"))) {
            ints.push_back(s);
        } else {
            for (int i = 0; i < s.size(); i++) {
                ll cur = s[i] == '*';
                if (s[i] == ' ')
                    continue;
                for (int j = i; j < s.size() && (i == j || s[j] == ' '); j++) {
                    bool ok = 0;
                    int curnum = 0;
                    int k = 0;
                    while (k < ints.size() && ints[k][j] == ' ')
                        k++;
                    for (; k < ints.size() && ints[k][j] != ' '; k++) {
                        ok = 1;
                        (curnum *= 10) += ints[k][j] - '0';
                    }
                    if (!ok)
                        continue;
                    s[i] == '+' ? cur += curnum : cur *= curnum;
                }
                ans += cur;
            }
        }
    }
    cout << ans << "\n";
}