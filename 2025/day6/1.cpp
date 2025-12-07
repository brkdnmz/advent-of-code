#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    vector<vector<int>> ints;
    ll ans = 0;
    while (getline(cin, s)) {
        // for operator line
        while (s.back() == ' ')
            s.pop_back();
        istringstream iss(s);
        if (regex_search(s, regex("\\d"))) {
            ints.push_back({});
            while (!iss.eof()) {
                int x;
                iss >> x;
                ints.back().push_back(x);
            }
        } else {
            int ptr = 0;
            while (!iss.eof()) {
                string c;
                iss >> c;
                ll cur = c == "*";
                for (int i = 0; i < ints.size(); i++)
                    c == "+" ? (cur += ints[i][ptr]) : (cur *= ints[i][ptr]);
                ptr++;
                ans += cur;
            }
        }
    }
    cout << ans << "\n";
}